# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 13:24:05 by ahonchar          #+#    #+#              #
#    Updated: 2018/05/03 18:22:50 by ahonchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wextra -Wall -Werror
SRC = ft_printf.c parse_percent.c parse_format.c valid.c del_minus.c processing_string.c my_ret.c process_int_precision.c processing_char.c proc_int.c proc_base.c ft_itoa_base.c proc_ptr.c ft_atoi.c ft_isdigit.c ft_memset.c ft_strchr.c ft_strcpy.c ft_strlen.c ft_strncpy.c ft_strnew.c ft_strjoin.c ft_itoa_long.c ft_itoa.c ft_strrev.c ft_strcmp.c ft_strclr.c
OBJ = ft_printf.o parse_percent.o parse_format.o valid.o del_minus.o processing_string.o my_ret.o process_int_precision.o processing_char.o proc_int.o proc_base.o ft_itoa_base.o proc_ptr.o ft_atoi.o ft_isdigit.o ft_memset.o ft_strchr.o ft_strcpy.o ft_strlen.o ft_strncpy.o ft_strnew.o ft_strjoin.o ft_itoa_long.o ft_itoa.o ft_strrev.o ft_strcmp.o ft_strclr.o
NAME = libftprintf.a

%.o:%.c
	$(CC) $(FLAGS) -c $^

all:$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
