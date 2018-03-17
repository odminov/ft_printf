/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 01:23:24 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/18 01:23:24 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		parse_flags(t_print *list, char **str)
{
	if (**str == '#')
	{
		list->specformat = 1;
		++(*str);
	}
	else if (**str == '0')
	{
		list->zero = 1;
		++(*str);
	}
	else if (**str == '-')
	{
		list->align = 1;
		++(*str);
	}
	else if (**str == '+')
	{
		list->sign = 1;
		++(*str);
	}
	else if (**str == ' ')
	{
		list->space = 1;
		++(*str);
	}
	else
		return ;
}

static void		parse_mods(t_print *list, char **str)
{
	list->typemod = **str;
	++(*str);
	if ((**str == 'h') || (**str == 'l'))
	{
		list->doublemod = 1;
		++(*str);
	}
}

static void		parse_width(t_print *list, char **str)
{
	int		i;
	char	width[11];

	i = 0;
	while (**str && ft_isdigit(**str))
	{
		width[i] = **str;
		++i;
		++(*str);
	}
	width[i] = '\0';
	list->width = ft_atoi(width);
}

static void		parse_pecision(t_print *list, char **str)
{
	char	precision[11];
	int		i;

	++(*str);
	i = 0;
	while ((**str) && (**str == '0'))
		++(*str);
	while (**str && ft_isdigit(**str))
	{
		precision[i] = **str;
		++i;
		++(*str);
	}
	precision[i] = '\0';
	list->precision = ft_atoi(precision);
}

void			parse_percent(char **str, t_print *list)
{
	while (**str && (!contains(TYPES, **str)))
	{
		if (contains(FLAGS, **str))
			parse_flags(list, str);
		else if (contains(MODS, **str))
			parse_mods(list, str);
		else if (ft_isdigit(**str))
			parse_width(list, str);
		else if (**str == '.')
			parse_pecision(list, str);
		else
			++(*str);
	}
	list->type = **str;
	if (**str)
		++(*str);
}