/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:39:01 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/16 12:52:11 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static void			processing_format(t_print *list, va_list arg)
{
	
}

static ssize_t		parse_and_print(char *format, va_list arg)
{
	t_print		*list;
	t_print		*temp;

	if (!(list = parse_format(format)))
		return (-1);
	temp = list;
	while (temp)
	{
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
		if (temp->type)
			processing_format(temp, arg);
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
