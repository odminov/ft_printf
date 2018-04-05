/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_str_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:09:24 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/05 16:43:23 by ahonchar         ###   ########.fr       */
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

	str = va_arg(arg, char *);
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
	char	c;
	int		len;

	c = '%';
	len = 1;
	str = ft_strnew(1);
	str[0] = c;
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
