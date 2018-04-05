# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 13:24:05 by ahonchar          #+#    #+#              #
#    Updated: 2018/04/05 23:03:34 by ahonchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wextra -Wall -Werror
SRC = main.c ft_printf.c parse_percent.c parse_format.c valid.c proc_str_chars.c proc_int.c proc_base.c ft_itoa_base.c proc_ptr.c
OBJ = main.o ft_printf.o parse_percent.o parse_format.o valid.o proc_str_chars.o proc_int.o proc_base.o ft_itoa_base.o proc_ptr.o
NAME = test

%.o:%.c
	$(CC) $(FLAGS) -c $^

All:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L ./libft/ -lft

clean:
	rm -rf *~
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean All

