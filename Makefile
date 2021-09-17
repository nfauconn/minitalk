NAME = minitalk
SERVER = server
CLIENT = client
CC = gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SHARED = minitalk_utils.c minitalk_utils1.c

OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SHARED = ${SRCS_SHARED:.c=.o}

all: ${NAME}

${NAME}: ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SHARED} ${OBJS_SERVER}
	@${CC} ${CFLAGS} ${INCLUDES} ${OBJS_SERVER} ${OBJS_SHARED} -o ${SERVER}
	@echo "${SERVER} created"

${CLIENT}: ${OBJS_SHARED} ${OBJS_CLIENT}
	@${CC} ${CFLAGS} ${INCLUDES} ${OBJS_CLIENT} ${OBJS_SHARED} -o ${CLIENT}
	@echo "${CLIENT} created"

.c.o:
	@echo create: ${@:%=%}
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@rm -rf ${OBJ_DIR}
	@echo "objs deleted"

fclean: clean
	@rm -rf ${SERVER} ${CLIENT}
	@echo "server and client deleted"

re: fclean all

.PHONY: all clean fclean re