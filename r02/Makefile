INC_DIR		= includes
SRC_DIR		= srcs/
SRCS		= ${SRC_DIR}dict_creator.c ${SRC_DIR}dict_handler.c ${SRC_DIR}dict_killer.c ${SRC_DIR}main.c ${SRC_DIR}reader.c ${SRC_DIR}split.c ${SRC_DIR}utils.c ${SRC_DIR}utils2.c

OBJS		= ${SRCS:.c=.o}

NAME		= rush-02

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
