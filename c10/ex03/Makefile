INC_DIR		= includes
SRC_DIR		= srcs
SRCS		= ${SRC_DIR}/main.c ${SRC_DIR}/reader.c ${SRC_DIR}/str_utils.c ${SRC_DIR}/tools.c

OBJS		= ${SRCS:.c=.o}

NAME		= ft_hexdump

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
