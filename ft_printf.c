/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:39:01 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/05 13:10:09 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdio.h> //delete <-------------------------------------------------

static int			processing_format_part1(t_print *list, va_list arg)
{
	if (list->type == '%')
	{
		if (processing_percent(list) != 1)
		{
			return (-1);
		}
	}
	else if (list->type == 's')
	{
		if (processing_string(list, arg) != 1)
		{
			return (-1);
		}
	}
	else if (list->type == 'S')
	{
		if (processing_string(list, arg) != 1)
		{
			return (-1);
		}
	}
	// else if (list->type == 'p' && processing_pointer(list, arg) != 1)
	// 	return (-1);
	else if (list->type == 'd')
	{
		if (processing_number(list, arg) != 1)
		{
			return (-1);
		}
	}
	else if (list->type == 'D')
	{
		if (processing_number(list, arg) != 1)
		{
			return (-1);
		}
	}
	else if (list->type == 'i')
	{
		if (processing_number(list, arg) != 1)
		{
			return ( -1);
		}
	}
	// else if (list->type == 'o' && processing_octal(list, arg) != 1)
	// 	return (-1);
	// else if (list->type == 'O' && processing_octal(list, arg) != 1)
	// 	return (-1);
	else
	{
		return (0);
	}
	return (1);
}

static int			processing_format_part2(t_print *list, va_list arg)
{
	if (list->type == 'c' && processing_char(list, arg) != 1)
	{
		return (-1);
	}
	else if (list->type == 'C' && processing_char(list, arg) != 1)
	{
		return (-1);
	}
	else if (list->type == 'u' && processing_number(list, arg) != 1)
		return (-1);
	else if (list->type == 'U' && processing_number(list, arg) != 1)
		return (-1);
	// else if (list->type == 'x' && processing_hex(list, arg) != 1)
	// 	return (-1);
	// else if (list->type == 'X' && processing_hex(list, arg) != 1)
	// 	return (-1);	
	else
	{
		return (0);
	}
	return (1);
}

static int	my_ret(t_print *list, int ret)
{
	while (list)
	{
		if (list->out)
			free(list->out);
		free(list);
		list = list->next;
	}
	return (ret);
}

static ssize_t		parse_and_print(char *format, va_list arg)
{
	t_print		*list;
	t_print		*temp;
	ssize_t		written_bytes;
	int			ret;

	if (!(list = parse_format(format)))
		return (-1);
	temp = list;
	if (arg)
		;
	ret = 0;
	written_bytes = 0;
	while (temp)
	{
		if (temp->type != '\0')
		{
			if ((ret = processing_format_part1(temp, arg)) != 1)
			{
				if (ret < 0)
					return (my_ret(list, -13));
				if (!ret && (ret = processing_format_part2(temp, arg)) < 0)
					return (my_ret(list, -14));
			}
		}
		if (temp->out)
			written_bytes += write(1, temp->out, ft_strlen(temp->out));
		// printf("align: %i\n", temp->align);
		// printf("sign: %i\n", temp->sign);
		// printf("space: %i\n", temp->space);
		// printf("specformat: %i\n", temp->specformat);
		// printf("zero: %i\n", temp->zero);
		// printf("width: %d\n", temp->width);
		// printf("precision: %d\n", temp->precision);
		// printf("typemod: %c\n", temp->typemod);
		// printf("doublemod:\"%d\"\n", temp->doublemod);
		// printf("type:\"%c\"\n", temp->type);
		// printf("out:\"%s\"\n", temp->out);
		// printf("-------------------\n");			
		temp = temp->next;
	}
	return (my_ret(list, written_bytes));
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	ssize_t	out;

	out = 0;
	if (!contains((char *)format, '%'))
	{
		out = write(1, format, ft_strlen(format));
		return ((int)out);
	}
	else
	{
		if (!valid((char *)format))
			return (-1);
		va_start(arg, format);
		out = parse_and_print((char *)format, arg);
		va_end(arg);
		return ((int)out);
	}
}
