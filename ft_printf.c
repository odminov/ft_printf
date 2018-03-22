/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:39:01 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/22 18:24:36 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdio.h>

// static int			processing_format_part1(t_print *list, va_list *arg)
// {
// 	if (list->type == '%')
// 		processing_percent(list, arg);
// 	else if (list->type == 's')
// 		processing_string(list, arg);
// 	else if (list->type == 'S')
// 		processing_string(list, arg);
// 	else if (list->type == 'p')
// 		processing_pointer(list, arg);
// 	else if (list->type == 'd')
// 		processing_integer(list, arg);
// 	else if (list->type == 'D')
// 		processing_integer(list, arg);
// 	else if (list->type == 'i')
// 		processing_integer(list, arg);
// 	else if (list->type == 'o')
// 		processing_octal(list, arg);
// 	else if (list->type == 'O')
// 		processing_octal(list, arg);
// 	else
// 		return (0);

// 	return (1);
// }

// static int			processing_format_part2(t_print *list, va_list *arg)
// {
// 	if (list->type == 'u')
// 		processing_unsigned(list, arg);
// 	else if (list->type == 'U')
// 		processing_unsigned(list, arg);
// 	else if (list->type == 'x')
// 		processing_hex(list, arg);
// 	else if (list->type == 'X')
// 		processing_hex(list, arg);
// 	else if (list->type == 'c')
// 		processing_char(list, arg);
// 	else if (list->type == 'C')
// 		processing_char(list, arg);
// 	else
// 		return (0);
// 	return (1);
// }

static ssize_t		parse_and_print(char *format, va_list arg)
{
	t_print		*list;
	t_print		*temp;

	if (!(list = parse_format(format)))
		return (-1);
	temp = list;
	while (temp)
	{
		if (temp->type == 's')
		{
			if (processing_string(temp, arg, format) < 0)
				return (-1);
		}
		else if (temp->type == 'd')
		{
			if (processing_integer(temp, arg) < 0)
				return (-1);
		}
		else if (temp->type == 'c')
		{
			if (processing_char(temp, arg) < 0)
				return (-1);
		}
		else
			;
		printf("align: %i\n", temp->align);
		printf("sign: %i\n", temp->sign);
		printf("space: %i\n", temp->space);
		printf("specformat: %i\n", temp->specformat);
		printf("zero: %i\n", temp->zero);
		printf("width: %d\n", temp->width);
		printf("precision: %d\n", temp->precision);
		printf("typemod: %c\n", temp->typemod);
		printf("doublemod:\"%d\"\n", temp->doublemod);
		printf("type:\"%c\"\n", temp->type);
		printf("out:\"%s\"\n", temp->out);
		printf("-------------------\n");
		// if (temp->type)
		// 	if (!processing_format(temp, &arg))
		// 		processing_format_part2(temp, &arg);
		
		temp = temp->next;
	}
	return (1);
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
