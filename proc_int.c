/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 10:12:08 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/27 16:48:00 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*without_precision(t_print *list, char *out, char *prefix)
{
	char	*temp;
	int		add;


	add = 0;
	if (list->sign || list->space || list->zero)
		add = 1;
	if (list->width > (int)ft_strlen(out) + add)
	{
		temp = proc_width(list, out, (int)ft_strlen(out), '0', add);
		out = ft_strjoin(prefix, temp);
		free(temp);
	}
	else
	{
		temp = out;
		out = ft_strjoin(prefix, out);
		free(temp);
	}
	return (out);
}

static char	*process_int_precision(t_print *list, char **out, char *prefix)
{
	int		i;
	char	*temp;

	if (list->set_precision)
	{
		if (list->precision > (int)ft_strlen(*out))
		{
			temp = prefix;
			if (*prefix)
				++prefix;
			i = list->precision - ft_strlen(*out);
			while (i-- > 0)
				*prefix++ = '0';
			prefix = temp;
		}
		temp = *out;
		if (!(*out = ft_strjoin(prefix, *out)))
			return (NULL);
		free(temp);
		if (list->width > (int)ft_strlen(*out))
			return (proc_width(list, *out, (int)ft_strlen(*out), ' ', 0));
		return (*out);
	}
	return (without_precision(list, *out, prefix));
}

static void	delete_minus(char **src)
{
	char	*new;
	char	*temp;
	int		i;

	temp = *src;
	new = (char *)malloc(ft_strlen(*src));
	i = 0;
	while (**src)
	{
		if (**src == '-')
		{	
			++(*src);
			continue;
		}
		new[i++] = **src;
		++(*src);
	}
	new[i] = '\0';
	free(temp);
	*src = new;
}

int			processing_integer(t_print *list, va_list arg)
{
	int		count;
	char	*out;
	char	*prefix;

	prefix = ft_strnew(11);
	count = va_arg(arg, int);
	if (!(out = ft_itoa(count)))
		return (-1);
	if (list->sign)
	{
		if (count < 0)
			prefix[0] = '-';
		else
			prefix[0] = '+';
	}
	if (!(list->sign) && (list->space))
	{
		if (count < 0)
			prefix[0] = '-';
		else
			prefix[0] = ' ';
	}
	if (count < 0)
		delete_minus(&out);
	if (!(list->out = process_int_precision(list, &out, prefix)))
		return (-1);
	free(prefix);
	if (list->width > (int)ft_strlen(out))
		free(out);
	return (1);
}
