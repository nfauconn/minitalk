NAME		=	libft.a

OBJ_DIR		=	objs/
SRC_DIR		=	srcs/

SRC			=	ft_atoi.c \
				ft_atoi_base.c\
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_nbrlen_base.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strdup.c \
				ft_strfdup.c \
				ft_strfjoin.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_ulltoa_base.c \
				get_next_line.c \
				rev_int_tab.c \
				sort_int_tab.c \



INCLUDES	=	-I includes/libft.h -I includes/ft_printf.h -I includes/get_next_line.h

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
COMP		=	$(CC) $(CFLAGS) ${INCLUDES}
RM			=	rm -rf

OBJ			=	${SRC:%.c=%.o}
SRC_PATH	=	$(SRC:%=$(SRC_DIR)%)
OBJ_PATH =	${addprefix ${OBJ_DIR}, ${OBJ}}

all :		${NAME}

$(OBJ_DIR):
			mkdir -p ${OBJ_DIR}  2> /dev/null || true


${OBJ_PATH}:	${SRC_PATH}
				@${MAKE} ${OBJ}

${OBJ}:	${OBJ_DIR} 
				@echo Create: ${@:obj/%=%}"\x1b[1A\x1b[M"
				@${COMP} -c -o ${OBJ_DIR}$@ ${SRC_DIR}${@:%.o=%.c}



$(NAME): 	${OBJ_PATH}
			@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OBJ))
			@ranlib $(NAME)

clean:		
			@${RM} ${OBJ_DIR}
		

fclean:		clean
			@${RM} *.a
			
re:			fclean all

.PHONY:		all clean fclean re
