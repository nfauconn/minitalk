# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 15:54:29 by nfauconn          #+#    #+#              #
#    Updated: 2024/01/27 15:54:30 by nfauconn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minitalk
SERVER := server
CLIENT := client
CC := gcc
CFLAGS	:= -Wall -Wextra -Werror

SRCS_SERVER := server.c minitalk_utils.c minitalk_utils1.c
SRCS_CLIENT := client.c minitalk_utils.c minitalk_utils1.c

OBJS_SERVER := ${SRCS_SERVER:.c:=.o}
OBJS_CLIENT := ${SRCS_CLIENT:.c:=.o}

all: ${NAME}

${NAME}: ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SERVER} minitalk.h
	${CC} ${CFLAGS} ${OBJS_SERVER} -o ${SERVER}
	@echo "${SERVER} created"

${CLIENT}: ${OBJS_CLIENT} minitalk.h
	${CC} ${CFLAGS} ${OBJS_CLIENT} -o ${CLIENT}
	@echo "${CLIENT} created"

%.c: %.o
	echo create: ${@:%:=%}
	@${CC} -g -c -o ${<:.c:=.o} $< ${CFLAGS}

clean:
	@rm -rf *.o
	@echo "objs deleted"

fclean: clean
	@rm -rf ${SERVER} ${CLIENT}
	@echo "server and client deleted"

re: fclean all

.PHONY: all clean fclean re