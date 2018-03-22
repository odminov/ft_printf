/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_str_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:09:24 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/22 18:28:00 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

static char	*proc_width(t_print *list, char *src, int len, char c)
{
	char	*out;
	int		i;

	if (!(out = (char *)malloc(list->width + 1)))
		return (NULL);
	i = list->width - len;
	if (!list->align)
	{
		ft_memset(out, c, i);
		while (i < (list->width))
			out[i++] = *src++;
		out[i] = '\0';
		return (out);
	}
	i = 0;
	while (i < list->width)
	{
		if (i < len)
			out[i] = src[i];
		else
			out[i] = c;
		i++;
	}
	out[i] = '\0';
	return (out);
}

int			processing_string(t_print *list, va_list arg, char *format)
{
	char	*out;
	char	*str;
	int		len;
	char	c;

	c = ' ';
	str = va_arg(arg, char *);
	if (str < format)
		return (-1);
	len = (int)ft_strlen(str);
	if ((list->precision) && (list->precision < len))
		len = list->precision;
	if ((list->width) && (list->width > len))
	{
		if (list->zero)
			c = '0';
		if (!(list->out = proc_width(list, str, len, c)))
			return (-1);
	}
	else
	{
		if (!(out = (char *)malloc(len + 1)))
			return (-1);
		list->out = ft_strncpy(out, str, len);
	}
	return (1);
}

int			processing_char(t_print *list, va_list arg)
{
	char	*out;
	char	*str;
	char	c;
	int		len;

	c = (char)va_arg(arg, unsigned);
	len = 1;
	str = ft_strnew(1);
	str[0] = c;
	c = ' ';
	if ((list->width) && (list->width > len))
	{
		if (list->zero)
			c = '0';
		if (!(list->out = proc_width(list, str, len, c)))
			return (-1);
	}
	else
	{
		if (!(out = (char *)malloc(len + 1)))
			return (-1);
		list->out = ft_strncpy(out, str, len);
	}
	return (1);
}

int			processing_integer(t_print *list, va_list arg)
{
	int		temp;

	temp = va_arg(arg, int);
	list->out = ft_itoa(temp);
	return (1);
}
