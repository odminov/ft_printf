/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 10:12:08 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/29 21:33:24 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*int_without_precision(t_print *list, char *out, char *prefix)
{
	char	*temp;
	int		add;


	add = 0;
	if (list->sign || list->space)
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
	return (int_without_precision(list, *out, prefix));
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

void		check_type(t_print *list, va_arg arg, char **out)
{
	unsigned long long	u_num;
	signed long long	u_num;
	int 				i_num;

	if (list->type == 'd' || list->type == 'i' && list->typemod == 'l')

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
}

int			processing_integer(t_print *list, va_list arg)
{
	char	*out;
	char	*prefix;

	prefix = ft_strnew(21);
	check_type(list, arg, &out);
	if (!(list->out = process_int_precision(list, &out, prefix)))
		return (-1);
	free(prefix);
	if (list->width > (int)ft_strlen(out))
		free(out);
	return (1);
}
