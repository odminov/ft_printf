/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_str_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:09:24 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/17 14:09:36 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*proc_width(t_print *list, char *src, int len, char c)
{
	char	*out;
	int		i;

	if (!(out = (char *)malloc(list->width + 1)))
		return (NULL);
	i = list->width - len - (list->add);
	if (!list->align)
	{
		ft_memset(out, c, i);
		while (i < (list->width))
			out[i++] = *src++;
		out[i] = '\0';
		return (out);
	}
	i = 0;
	while (i < (list->width) - (list->add))
	{
		if (i < len)
			out[i] = src[i];
		else
			out[i] = ' ';
		i++;
	}
	out[i] = '\0';
	return (out);
}

int			processing_string(t_print *list, va_list arg)
{
	char	*out;
	char	*str;
	int		len;
	char	err_11[7];

	ft_strcpy(err_11, "(null)");
	str = va_arg(arg, char *);
	if (!str)
		str = err_11;
	len = (int)ft_strlen(str);
	if ((list->set_precision) && (list->precision < len))
		len = list->precision;
	if ((list->width) && (list->width > len))
	{
		if (!(list->out = proc_width(list, str, len, ' ')))
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

void		parse_unicode(char *str, unsigned value)
{
	if (value < 128)
		str[0] = value;
	else if (value > 127 && value < 2048)
	{
		str[0] = value >> 6 | 0xC0;
		str[1] = value << 24 >> 24 | 0x80;
	}
	else if (value > 2047 && value < 65536)
	{
		str[0] = value >> 12 | 0xE0;
		str[1] = (value << 16 >> 16) >> 6 | 0x80;
		str[2] = value << 24 >> 24 | 0x80;
	}
	else
	{
		str[0] = value >> 18 | 0xF0;
		str[1] = (value << 8 >> 8) >> 12 | 0x80;
		str[2] = (value << 16 >> 16) >> 6 | 0x80;
		str[3] = value << 24 >> 24 | 0x80;
	}
}

int			processing_char(t_print *list, va_list arg)
{
	char	*out;
	char	*str;
	char	c;
	int		len;

	str = ft_strnew(4);
	if (list->type == 'c')
		str[0] = (char)va_arg(arg, unsigned);
	else
		parse_unicode(str, va_arg(arg, unsigned));
	if ((list->width) && (list->width > len))
	{
		if (!(list->out = proc_width(list, str, len, ' ')))
			return (-1);
	}
	else
	{
		if (!(out = (char *)malloc(len + 1)))
			return (-1);
		list->out = ft_strncpy(out, str, len);
	}
	free(str);
	return (1);
}

int			processing_percent(t_print *list)
{
	char	*out;
	char	*str;
	int		len;

	len = 1;
	str = ft_strnew(1);
	str[0] = '%';
	if ((list->width) && (list->width > len))
	{
		if (!(list->out = proc_width(list, str, len, ' ')))
			return (-1);
	}
	else
	{
		if (!(out = (char *)malloc(len + 1)))
			return (-1);
		list->out = ft_strncpy(out, str, len);
	}
	free(str);
	return (1);
}
