####### DESIGN #######

# Style de typo :
_FIN			=	\033[0m
_GRAS			=	\033[1m
_ITA			=	\033[3m
_SOUS			=	\033[4m
_CLIGN			=	\033[5m
_REV			=	\033[7m

# Couleurs des lettres :
_GRIS			=	\033[30m
_ROUGE			=	\033[31m
_VERT			=	\033[32m
_JAUNE			=	\033[33m
_BLEU			=	\033[34m
_VIOLET			=	\033[35m
_CYAN			=	\033[36m
_BLANC			=	\033[37m

# Couleurs de fonds :
_IGRIS			=	\033[40m
_IROUGE			=	\033[41m
_IVERT			=	\033[42m
_IJAUNE			=	\033[43m
_IBLEU			=	\033[44m
_IVIOLET		=	\033[45m
_ICYAN			=	\033[46m
_IBLANC			=	\033[47m

# Appel
_VALID			=	/bin/echo -e "${_VERT}${_IBLANC}\#\# $1${_FIN}"
_EMOJI			=	/bin/echo -e "${_GRAS}${_VIOLET}$1${_FIN}\n"

CREATED_BIN		=	@$(call _VALID,"Binary created!")
CREATED_LIB		=	@$(call _VALID,"Library created!")
DELETED_OBJS	=	@$(call _VALID,"Objs deleted!")
DELETED_BIN		=	@$(call _VALID,"Binary deleted!")
TRANQUER		=	@$(call _EMOJI,"（ ^_^）o自自o（^_^ ）")
THROW_TABLE		=	@$(call _EMOJI, "（╯°□°）╯︵ ┻━┻" )
THROW_TABLE2	=	@$(call _EMOJI, "┻━┻ ︵ヽ（\`━\'）ﾉ︵ ┻━┻")


####### MAKEFILE #######

### Variables

LIBFT_PATH		=	./librairies/libft/
LIBFT			=	${LIBFT_PATH}libft.a

MINILIBX_PATH	=	./librairies/minilibx/
MINILIBX		=	${MINILIBX_PATH}libmlx.a

SRCS_PATH		=	./srcs/
SRCS			=	${SRCS_PATH}main_test.c	\
					${SRCS_PATH}errors.c	\
					${SRCS_PATH}map.c	\
					${SRCS_PATH}valid_map.c

OBJS			=	${SRCS:.c=.o}

HEADER_PATH		=	./headers/
HEADER			=	${HEADER_PATH}so_long.h

NAME			=	so_long

CC				=	clang
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L. -lXext -L. -lX11

### Commandes

all:			${NAME}

${NAME}:		${OBJS} ${LIBFT} #${MINILIBX}
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}
				${CREATED_BIN}

.c.o:
				${CC} -c ${CFLAGS} -I${HEADER} $^ -o $@

${LIBFT}:
				make -C ${LIBFT_PATH}
				${CREATED_LIB}

${MINILIBX}:
				make -C ${MINILIBX_PATH}

clean:
				make -C ${LIBFT_PATH} clean
				#make -C ${MINILIBX_PATH} clean
				${RM} ${OBJS}
				${DELETED_OBJS}

fclean:			clean
				make -C ${LIBFT_PATH} fclean
				${RM} ${NAME}
				${DELETED_BIN}

re:				fclean all

.PHONY:			all clean fclean re libft minilibx
