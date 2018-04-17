/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:39:01 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/17 16:54:36 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

static int			processing_format_part1(t_print *list, va_list arg)
{
	if (list->type == '%' && processing_percent(list) != 1)
		return (-1);
	else if (list->type == 's' && processing_string(list, arg) != 1)
		return (-1);
	else if (list->type == 'S' && processing_string(list, arg) != 1)
		return (-1);
	else if (list->type == 'p' && processing_ptr(list, arg) != 1)
		return (-1);
	else if (list->type == 'd' && processing_number(list, arg) != 1)
		return (-1);
	else if (list->type == 'D' && processing_number(list, arg) != 1)
		return (-1);
	else if (list->type == 'i' && processing_number(list, arg) != 1)
		return ( -1);
	else if (list->type == 'o' && processing_oct(list, arg) != 1)
		return (-1);
	else if (list->type == 'O' && processing_oct(list, arg) != 1)
		return (-1);
	else
		return (0);
	return (1);
}

static int			processing_format_part2(t_print *list, va_list arg)
{
	if (list->type == 'c' && processing_char(list, arg) != 1)
		return (-1);
	else if (list->type == 'C' && processing_char(list, arg) != 1)
		return (-1);
	else if (list->type == 'u' && processing_number(list, arg) != 1)
		return (-1);
	else if (list->type == 'U' && processing_number(list, arg) != 1)
		return (-1);
	else if (list->type == 'x' && processing_hex(list, arg) != 1)
		return (-1);
	else if (list->type == 'X' && processing_hex(list, arg) != 1)
		return (-1);	
	else
		return (0);
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
	// if (arg)
	// 	;
	ret = 0;
	written_bytes = 0;
	while (temp)
	{
		if (temp->type != '\0')
		{
			if ((ret = processing_format_part1(temp, arg)) != 1)
			{
				if (ret < 0)
					return (my_ret(list, -1));
				if (!ret && (ret = processing_format_part2(temp, arg)) < 0)
					return (my_ret(list, -1));
			}
		}
		temp = temp->next;
	}
	temp = list;
	while (temp)
	{
		if (temp->out)
			written_bytes += write(1, temp->out, ft_strlen(temp->out));
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
