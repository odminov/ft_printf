/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:19:27 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/10 17:02:50 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		processing_hex(t_print *list, va_list arg)
{
	unsigned long	value;
	char			*out;
	char			*prefix;
	int				prefsize;

	if ((list->type == 'x' || list->type == 'X') && list->typemod == 'l')
		value = va_arg(arg, unsigned long);
	else
		value = va_arg(arg, unsigned);
	if (list->type == 'x')
		out = ft_itoa_base(value, 16, 0);
	else
		out = ft_itoa_base(value, 16, 1);
	prefsize = 2;
	if (list->precision - (int)ft_strlen(out) > 0)
		prefsize += list->precision - (int)ft_strlen(out);
	prefix = ft_strnew(prefsize);
	if (list->specformat && ft_strcmp(out, "0"))
		ft_strcpy(prefix, "0x");
	if ((!ft_strcmp(out, "0")) && (list->set_precision))
		*out = '\0';
	if (!(list->out = process_int_precision(list, &out, prefix)))
		return (0);
	free(prefix);
	if (list->width > (int)ft_strlen(out))
		free(out);
	return (1);
}

int		processing_oct(t_print *list, va_list arg)
{
	unsigned long	value;
	char			*out;
	char			*prefix;
	int				prefsize;

	if (list->type == 'O' || (list->type == 'o' && list->typemod == 'l'))
		value = va_arg(arg, unsigned long);
	else
		value = va_arg(arg, unsigned);
	out = ft_itoa_base(value, 8, 0);
	prefsize = 2;
	if ((!ft_strcmp(out, "0")) && (list->set_precision || list->specformat))
		*out = '\0';
	if (list->precision - (int)ft_strlen(out) > 0)
	{
		prefsize += list->precision - (int)ft_strlen(out);
		list->specformat = 0;
	}
	prefix = ft_strnew(prefsize);
	if (list->specformat)
		prefix[0] = '0';
	if (!(list->out = process_int_precision(list, &out, prefix)))
		return (0);
	free(prefix);
	if (list->width > (int)ft_strlen(out))
		free(out);
	return (1);
}
