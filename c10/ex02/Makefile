INC_DIR		= includes
SRC_DIR		= srcs
SRCS		= ${SRC_DIR}/ft_tail.c ${SRC_DIR}/ft_tail2.c ${SRC_DIR}/ft_utils.c ${SRC_DIR}/main.c

OBJS		= ${SRCS:.c=.o}

NAME		= ft_tail

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
