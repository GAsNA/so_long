# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleseur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 14:34:54 by rleseur           #+#    #+#              #
#    Updated: 2022/01/20 08:54:41 by rleseur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
_VALID			=	/bin/echo -e "${_JAUNE}\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\n\
					${_VERT}${_IVIOLET}\#\# $1${_FIN}"
_EMOJI			=	/bin/echo -e "${_GRAS}${_VIOLET}$1${_FIN}\n"

CREATED_BIN		=	@$(call _VALID,"Binary created!")
CREATED_LIBFT	=	@$(call _VALID,"Libft library created!")
CREATED_MINILX	=	@$(call _VALID,"Minilibx library created!")
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
SRCS			=	${SRCS_PATH}main.c			\
					${SRCS_PATH}errors.c		\
					${SRCS_PATH}map.c			\
					${SRCS_PATH}valid_map.c		\
					${SRCS_PATH}valid_map2.c	\
					${SRCS_PATH}window.c		\
					${SRCS_PATH}actions_win.c	\
					${SRCS_PATH}draw_map.c		\
					${SRCS_PATH}check_if_is.c	\
					${SRCS_PATH}moving.c		\
					${SRCS_PATH}part_init.c		\
					${SRCS_PATH}free.c

SRCS_B_PATH		=	./srcs_bonus/
SRCS_B			=	${SRCS_B_PATH}main.c			\
					${SRCS_B_PATH}errors.c			\
					${SRCS_B_PATH}map.c				\
					${SRCS_B_PATH}valid_map.c		\
					${SRCS_B_PATH}valid_map2.c		\
					${SRCS_B_PATH}window.c			\
					${SRCS_B_PATH}actions_win.c		\
					${SRCS_B_PATH}draw_map.c		\
					${SRCS_B_PATH}check_if_is.c		\
					${SRCS_B_PATH}moving.c			\
					${SRCS_B_PATH}put_params.c		\
					${SRCS_B_PATH}ennemy_animation.c\
					${SRCS_B_PATH}part_init.c		\
					${SRCS_B_PATH}free.c

OBJS			=	${SRCS:.c=.o}
OBJS_B			=	${SRCS_B:.c=.o}

HEADERS_PATH		=	./headers/
HEADER			=	${HEADERS_PATH}so_long.h
HEADER_B		=	${HEADERS_PATH}so_long_bonus.h

NAME			=	so_long
NAME_B			=	so_long_bonus

CC				=	clang
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -g3
MLXFLAGS		=	-L. -lXext -L. -lX11

### Commandes

all:			${NAME}

${NAME}:		${OBJS} ${LIBFT} ${MINILIBX}
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MINILIBX} ${MLXFLAGS} -o ${NAME}
				${CREATED_BIN}

bonus:			${NAME_B}

${NAME_B}:		${OBJS_B} ${LIBFT} ${MINILIBX}
				${CC} ${CFLAGS} ${OBJS_B} ${LIBFT} ${MINILIBX} ${MLXFLAGS} -o ${NAME_B}
				${CREATED_BIN}

.c.o:
				${CC} -c ${CFLAGS} -I${HEADER} $^ -o $@

${LIBFT}:
				make -C ${LIBFT_PATH}
				${CREATED_LIBFT}

${MINILIBX}:
				make -C ${MINILIBX_PATH}
				${CREATED_MINILX}

clean:
				make -C ${LIBFT_PATH} clean
				make -C ${MINILIBX_PATH} clean
				${RM} ${OBJS}
				${RM} ${OBJS_B}
				${DELETED_OBJS}

fclean:			clean
				make -C ${LIBFT_PATH} fclean
				${RM} ${NAME}
				${RM} ${NAME_B}
				${DELETED_BIN}

re:				fclean all

.PHONY:			all bonus clean fclean re libft minilibx
