# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 21:07:04 by nfauconn          #+#    #+#              #
#    Updated: 2021/08/19 17:17:04 by nfauconn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIB_A	=	libft.a
LIB =	../..

OBJ_DIR		=	objs/
SRC_DIR		=	srcs/

SRC			= 	conv_c.c\
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
				parse_printf.c\

INCLUDES	=	-I ./includes/


CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
COMP		=	$(CC) $(CFLAGS) ${INCLUDES}
RM			=	rm -rf

OBJ			=	${SRC:%.c=%.o}
SRC_PATH	=	$(SRC:%=$(SRC_DIR)%)
OBJ_PATH =	${addprefix ${OBJ_DIR}, ${OBJ}}


all :		${NAME}

make_lib:
				@make -C $(LIB)
				@cp $(LIB)/*.a .

$(OBJ_DIR):
			@mkdir -p ${OBJ_DIR}

$(OBJ):		${OBJ_DIR} 
			@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
			@${COMP} -c -o ${OBJ_DIR}$@ ${SRC_DIR}${@:%.o=%.c}

${OBJ_PATH}:	
				@${MAKE} ${OBJ}

$(NAME): 	make_lib ${OBJ_PATH}
			@libtool -static -o $(NAME) $(LIB_A) $(addprefix $(OBJ_DIR), $(OBJ))

clean:
			@${RM} ${OBJ_DIR}
				@make -C $(LIB) clean

fclean:		clean
			@${RM} *.a
			@make -C $(LIB) fclean


re:			fclean all

.PHONY:		all clean fclean re

