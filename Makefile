# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 15:26:20 by abelahce          #+#    #+#              #
#    Updated: 2022/08/08 05:33:24 by abelahce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all: minishell

CC=gcc

HEADER=minishell.h

UTILS=utils.o

CFLAGS=-Wall -Wextra -Werror -g -pthread 

NAME=minishell

SRC := main.c \
		minishell.c	\

OBJ := $(SRC:.c=.o)

HDR := minishell.h

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf  $(OBJ)

fclean: clean
	rm -rf minishell

re: fclean all