# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afons <afons@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 23:24:56 by afons             #+#    #+#              #
#    Updated: 2026/01/30 21:34:39 by afons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= cc
CFLAGSSS	:= -Wall -Wextra -Werror -g
NAME		:= pipex
SRCS		:= \
		sources/pipex.c \
		sources/execution.c \
		sources/free_all.c \
		sources/ft_bzero.c \
		sources/ft_calloc.c \
		sources/ft_memset.c \
		sources/ft_split.c \
		sources/ft_strdup.c \
		sources/ft_strjoin.c \
		sources/ft_strncmp.c \
		sources/ft_substr.c \
		sources/parsing.c \
		sources/prog.c

OBJS		:= ${SRCS:.c=.o}
LD_FLAGS	:= -Lft_printf 
LD_LIBS		:= -lftprintf
INCLUDES	:= -Iincludes -Ift_printf/includes

%.o : %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS}
	${MAKE} -C ./ft_printf
	${CC} ${OBJS} ${LD_FLAGS} ${LD_LIBS} -o $@

clean :
	${MAKE} -C ./ft_printf clean
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean 
	${MAKE} all

.PHONY : all fclean clean re