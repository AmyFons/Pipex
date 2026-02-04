# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afons <afons@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 18:08:36 by afons             #+#    #+#              #
#    Updated: 2026/01/30 01:42:14 by afons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
NAME		:= libftprintf.a

SRCS		:= \
		ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_puthexa.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_printpercent.c \
		ft_putnbr_unsigned.c \
		ft_putptr.c

OBJTS		:= ${SRCS:.c=.o}
INCLUDES	:= -Iincludes

%.o : %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJTS}
	ar rcs $@ ${OBJTS}

clean :
	rm -rf ${OBJTS}

fclean : clean
	rm -rf ${NAME}

re : fclean 
	${MAKE} all

.PHONY : all fclean clean re         