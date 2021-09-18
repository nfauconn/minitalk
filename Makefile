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
	${CC} ${OBJS_SERVER} -o ${SERVER}
	@echo "${SERVER} created"

${CLIENT}: ${OBJS_CLIENT} minitalk.h
	${CC} ${OBJS_CLIENT} -o ${CLIENT}
	@echo "${CLIENT} created"

%.c: %.o
	echo create: ${@:%:=%}
	@${CC} -g -c -o ${<:.c:=.o} $< ${CFLAGS}

clean:
	@rm -rf ${OBJ_DIR}
	@echo "objs deleted"

fclean: clean
	@rm -rf ${SERVER} ${CLIENT}
	@echo "server and client deleted"

re: fclean all

.PHONY: all clean fclean re