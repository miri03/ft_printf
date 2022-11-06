# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meharit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 10:47:03 by meharit           #+#    #+#              #
#    Updated: 2022/11/06 13:55:32 by meharit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBC = ar rc

SRC = ft_printf.c \
	  out_put.c \
	  afunc.c \

OBJ = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${LIBC} ${NAME} ${OBJ}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}
