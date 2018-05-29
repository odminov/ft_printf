# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 13:24:05 by ahonchar          #+#    #+#              #
#    Updated: 2018/05/08 12:20:31 by ahonchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wextra -Wall -Werror

HEADERS = ft_printf.h header.h

SRC = ft_printf.c parse_percent.c parse_format.c valid.c del_minus.c processing_string.c my_ret.c process_int_precision.c processing_char.c proc_int.c proc_base.c ft_itoa_base.c proc_ptr.c ft_atoi.c ft_isdigit.c ft_memset.c ft_strchr.c ft_strcpy.c ft_strlen.c ft_strncpy.c ft_strnew.c ft_strjoin.c ft_itoa_long.c ft_strrev.c ft_strcmp.c ft_strclr.c

DIR_OBJ = obj/

OBJ = $(addprefix $(DIR_OBJ), $(SRC:.c=.o))

NAME = libftprintf.a

$(DIR_OBJ)%.o:%.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

all:$(NAME)

$(NAME): $(DIR_OBJ) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(DIR_OBJ):
	@mkdir $(DIR_OBJ)

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
