SRC_DIR		= srcs/
SRCS		= ${SRC_DIR}ft_putchar.c ${SRC_DIR}ft_swap.c ${SRC_DIR}ft_putstr.c ${SRC_DIR}ft_strlen.c ${SRC_DIR}ft_strcmp.c

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc

RM			= rm -f

RL			= ranlib

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RL} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
