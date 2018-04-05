/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:19:27 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/05 19:25:09 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		processing_hex(t_print *list, va_list arg)
{
	unsigned long	value;
	char			*out;
	char			*prefix;

	prefix = ft_strnew(11);
	if ((list->type == 'x' || list->type == 'X') && list->typemod == 'l')
		value = va_arg(arg, unsigned long);
	else
		value = va_arg(arg, unsigned);
	if (list->specformat)
	{
		prefix[0] = '0';
		prefix[1] = 'x';
	}
	if (list->type == 'x')
		out = ft_itoa_base(value, 16, 0);
	else
		out = ft_itoa_base(value, 16, 1);
	if (!(list->out = process_int_precision(list, &out, prefix)))
		return (0);
	free(prefix);
	if (list->width > (int)ft_strlen(out))
		free(out);
	list->add = 0;
	return (1);
}

int		processing_oct(t_print *list, va_list arg)
{
	unsigned long	value;
	char			*out;
	char			*prefix;

	prefix = ft_strnew(11);
	if (list->type == 'O' || (list->type == 'o' && list->typemod == 'l'))
		value = va_arg(arg, unsigned long);
	else
		value = va_arg(arg, unsigned);
	if (list->specformat)
		prefix[0] = '0';
	out = ft_itoa_base(value, 8, 0);
	if (!(list->out = process_int_precision(list, &out, prefix)))
		return (0);
	free(prefix);
	if (list->width > (int)ft_strlen(out))
		free(out);
	list->add = 0;
	return (1);
}
