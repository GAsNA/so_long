
####### MAKEFILE #######

### Variables

LIBFT_PATH	=	./librairies/libft/
LIBFT		=	${LIBFT_PATH}libft.a

MINILIBX_PATH	=
MINILIBX	=

SRCS_PATH	=	./srcs/
SRCS		=

OBJS		=	${SRCS:.c=.o}

HEADER_PATH	=	./headers/
HEADER		=	${HEADER_PATH}so_long.h

NAME		=	so_long

CC		=	clang
RM		=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L. -lXext -L. -lX11

### Commandes

all:			${NAME}

${NAME}:		${OBJS} ${LIBFT} ${MINILIBX}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MINILIBX} ${MLXFLAGS} -o ${NAME}

.c.o:
			${CC} -c ${CFLAGS} -I${HEADER} $^ -o $@

${LIBFT}:
			make -C ${LIBFT_PATH}

${MINILIBX}:
			make -C ${MINILIBX_PATH}

clean:
			make -C ${LIBFT_PATH} clean
			make -C ${MINILIBX_PATH} clean
			${RM} ${OBJS}

fclean:			clean
			make -C ${LIBFT_PATH} fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:			all clean fclean re libft
