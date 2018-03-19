# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 13:24:05 by ahonchar          #+#    #+#              #
#    Updated: 2018/03/16 13:24:05 by ahonchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
FLAGS = -Wextra -Wall -Werror
SRC = main.c ft_printf.c parse_percent.c parse_format.c valid.c
OBJ = main.o ft_printf.o parse_percent.o parse_format.o valid.o
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
