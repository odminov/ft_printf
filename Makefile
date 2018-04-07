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
SRC = ft_printf.c parse_percent.c parse_format.c valid.c proc_str_chars.c proc_int.c proc_base.c ft_itoa_base.c proc_ptr.c ft_atoi.c ft_isdigit.c ft_memset.c ft_strchr.c ft_strcpy.c ft_strlen.c ft_strncpy.c ft_strnew.c ft_strjoin.c ft_itoa_long.c ft_itoa.c ft_strrev.c
OBJ = ft_printf.o parse_percent.o parse_format.o valid.o proc_str_chars.o proc_int.o proc_base.o ft_itoa_base.o proc_ptr.o ft_atoi.o ft_isdigit.o ft_memset.o ft_strchr.o ft_strcpy.o ft_strlen.o ft_strncpy.o ft_strnew.o ft_strjoin.o ft_itoa_long.o ft_itoa.o ft_strrev.o
NAME = libftprintf.a

%.o:%.c
	$(CC) $(FLAGS) -c $^

All:$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf *~
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean All

