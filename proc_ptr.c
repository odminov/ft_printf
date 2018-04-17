/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 22:53:05 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/17 20:37:06 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		processing_ptr(t_print *list, va_list arg)
{
	char			*out;
	void			*value;
	char			*prefix;
	int				prefsize;

	value = va_arg(arg, void *);
	out = ft_itoa_base((unsigned long)value, 16, 0);
	prefsize = 2;
	if (list->precision - (int)ft_strlen(out) > 0)
		prefsize += list->precision - (int)ft_strlen(out);
	prefix = ft_strnew(prefsize);
	ft_strcpy(prefix, "0x");
	if (!(list->out = process_int_precision(list, out, prefix)))
		return (0);
	free(prefix);
	return (1);
}
