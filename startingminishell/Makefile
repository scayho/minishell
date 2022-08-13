# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 15:26:20 by abelahce          #+#    #+#              #
#    Updated: 2022/08/13 18:43:51 by abelahce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all: minishell

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g

NAME=minishell

SRC := main.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_strncmp.c \
		ft_strlen.c \
		

OBJ := $(SRC:.c=.o)

HDR := minishell.h

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -lreadline  $(OBJ) -o $(NAME)

clean :
	rm -rf  $(OBJ)

fclean: clean
	rm -rf minishell

re: fclean all

