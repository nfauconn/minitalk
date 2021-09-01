NAME = minitalk
SERVER = server
CLIENT = client
CC = clang
INCLUDES = -I includes/
CFLAGS	= -Wall -Wextra -Werror
FILES_SERVER = server.c
FILES_CLIENT = client.c
SRCS_SERVER = $(addprefix $(SRC_DIR)/,$(FILES_SERVER))
SRCS_CLIENT = $(addprefix $(SRC_DIR)/,$(FILES_CLIENT))
OBJS_SERVER = $(addprefix $(OBJ_DIR)/,$(FILES_SERVER:.c=.o))
OBJS_CLIENT = $(addprefix $(OBJ_DIR)/,$(FILES_CLIENT:.c=.o))
SRC_DIR  = ./srcs
OBJ_DIR  = ./objs

all: $(NAME)

${NAME}: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_SERVER) -o $(SERVER)
	@echo create: $(@:%=%)
	@echo "$(SERVER) created"

$(CLIENT): $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_CLIENT) -o $(CLIENT)
	@echo "$(CLIENT) created"

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re