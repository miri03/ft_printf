# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meharit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 10:47:03 by meharit           #+#    #+#              #
#    Updated: 2022/11/07 11:48:38 by meharit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

LIBC = ar rc

SRC = ft_printf.c \
	  out_put.c \
	  pfunc.c \

OBJ = ft_printf.o \
	  out_put.o \
	  pfunc.o \

all : ${NAME}

${NAME} : ${OBJ}
	${LIBC} ${NAME} ${OBJ}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all
