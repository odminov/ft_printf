/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:56:02 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/15 11:57:13 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_format(char **str)
{
	int		mods;

	mods = 0;
	while (**str && (contains(FLAGS, **str)))
		++(*str);
	while (**str && ft_isdigit(**str))
		++(*str);
	if (**str == '.' && (++(*str)))
		while (**str && ft_isdigit(**str))
			++(*str);
	while (**str && (contains(MODS, **str)))
	{
		if ((++mods) == 2)
			if (**str != 'l' && **str != 'h')
				return (0);
		if (mods > 2)
			return (0);
		++(*str);
	}
	if (**str && !contains(TYPES, **str))
		return (0);
	++(*str);
	return (1);
}

int			valid(char *format)
{
	char	*ptr;

	while ((ptr = ft_strchr(format, '%')))
	{
		++ptr;
		if (!*ptr)
			return (0);
		if (!check_format(&ptr))
			return (0);
		format = ptr;
	}
	return (1);
}
