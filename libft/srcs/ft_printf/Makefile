# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 21:07:04 by nfauconn          #+#    #+#              #
#    Updated: 2021/09/08 19:24:01 by nfauconn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = ../../libft.a
LIBFT = ../../
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I ../../includes/
COMP = ${CC} ${CFLAGS} ${INCLUDES}
RM = rm -rf
CFILES = conv_c.c\
		conv_s.c\
		conv_p.c\
		conv_d_i.c\
		conv_u.c\
		conv_x.c\
		conv_mx.c\
		conv_percent.c\
		convert.c\
		fill_nb.c\
		ft_isflagpf.c\
		ft_printf.c\
		init_printf.c\
		insert_into_buffer.c\
		main_loop.c\
		parse_printf.c
SRCS = ${addprefix ${SRC_DIR}/,${CFILES}}
OBJS = ${addprefix ${OBJ_DIR}/,${CFILES:.c=.o}}
SRC_DIR  = ./srcs
OBJ_DIR  = ./objs

all: ${NAME}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}	
	@echo "lib_ftprintf created"

${OBJ_DIR}/%.o:${SRC_DIR}/%.c
	@mkdir -p ${OBJ_DIR}
	@echo create: ${@:%=%}
	@${CC} ${CFLAGS} ${INCLUDES} -o $@ -c $<

clean:
	@${RM} ${OBJ_DIR}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re