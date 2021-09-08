NAME = libft.a
FT_PRINTF = srcs/ft_printf
CC	 = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/
COMP = ${CC} ${CFLAGS} ${INCLUDES}
RM	 = rm -rf
CFILES = ft_atoi.c \
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
		str_isdigit.c \
		strfjoinchar.c \

SRCS = ${addprefix ${SRC_DIR}/,${CFILES}}
OBJS = ${addprefix ${OBJ_DIR}/,${CFILES:.c=.o}}
SRC_DIR  = ./srcs
OBJ_DIR  = ./objs

all : ${NAME}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "lib created"

${OBJ_DIR}/%.o:${SRC_DIR}/%.c
	@mkdir -p ${OBJ_DIR}
	@echo create: ${@:%=%}
	@${CC} ${CFLAGS} ${INCLUDES} -o $@ -c $<

clean:
	@${RM} ${OBJ_DIR}
	@make clean -C ${FT_PRINTF}
	@echo "objs lib deleted"

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${FT_PRINTF}
	@echo "lib deleted"
			
re: fclean all

.PHONY: all clean fclean re