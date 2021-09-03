NAME = minitalk
LIBFT = libft/
LIBFT_PRINTF = ./libft/srcs/ft_printf/
LIB = libft/libft.a libft/srcs/ft_printf/libftprintf.a
OBJ_LIB = libft/srcs/ft_printf/objs libft/objs
SERVER = server
CLIENT = client
CC = clang
INCLUDES = -I includes/ -I libft/includes/ -I libft/srcs/ft_printf/includes
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

${NAME}: makelibs $(SERVER) $(CLIENT)

makelibs: 
	@make -C $(LIBFT)
	@make -C $(LIBFT_PRINTF)

$(SERVER): $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIB) $(OBJS_SERVER) -o $(SERVER)
	@echo "$(SERVER) created"

$(CLIENT): $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIB) $(OBJS_CLIENT) -o $(CLIENT)
	@echo "$(CLIENT) created"

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo create: $(@:%=%)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_LIB)
	@echo "objs deleted"

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)
	@echo "server and client deleted"
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re