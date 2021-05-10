# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esivre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/31 12:16:04 by esivre            #+#    #+#              #
#    Updated: 2021/04/01 08:35:41 by esivre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addprefix ${FOLDER}/, check_solve.c init.c map.c print.c split.c utils.c main.c memmgr.c solve.c str.c)
OBJS	= ${SRCS:.c=.o}

FOLDER 	=	srcs
NAME	=	bsq
CC		=	gcc
CFLAGS  =	-Wall -Wextra -Werror

.c.o:		
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}
	

all:		${NAME}

${NAME}:	${OBJS} 
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} 


clean:
						rm -f ${OBJS}

fclean:		clean
						rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
