/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:39:01 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/16 12:52:11 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#define TYPES	"sSpdDioOuUxXcC"
#define FLAGS	"#0-+ "
#define MODS	"hljz"

int			contains(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (c);
		++i;
	}
	return (0);
}

int			sizebeforechr(char *str, char c)
{
	int i;

	i = 0;
	while(str[i] && str[i] != c)
	{
		++i;
	}
	return (i);
}

t_print		*init_list(void)
{
	t_print		*new;

	if (!(new = (t_print *)malloc(sizeof(t_print))))
		return (NULL);
	new->align = 0;
	new->sign = 0;
	new->space = 0;
	new->specformat = 0;
	new->zero = 0;
	new->width = 0;
	new->precision = 0;
	new->typemod = '\0';
	new->doublemod = 0;
	new->type = '\0';
	new->out = NULL;
	new->next = NULL;
	return (new);
}

void		parse_flags(t_print *list, char **str)
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

void		parse_mods(t_print *list, char **str)
{
	list->typemod = **str;
	++(*str);
	if ((**str == 'h') || (**str == 'l'))
	{
		list->doublemod = 1;
		++(*str);
	}
}

void		parse_width(t_print *list, char **str)
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

void		parse_pecision(t_print *list, char **str)
{
	char	precision[11];
	int		i;

	++(*str);
	i = 0;
	while (**str && **str == '0')
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

void		parse_percent(char **str, t_print *list)
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

int			copytolist(char **str, t_print *list)
{
	int i;

	i = 0;
	i = sizebeforechr(*str, '%');
	if (i)
	{
		if (!(list->out = (char *)malloc(i + 1)))
			return (-1);
		if (contains(*str, '%'))
			ft_memccpy(list->out, *str, '%', i);
		else
			ft_memccpy(list->out, *str, '\0', i);
		list->out[i] = '\0';
	}
	*str += i + 1;
	return (i);
}

t_print		*parse_format(char *format)
{
	t_print 	*new;
	t_print		*head;

	new = init_list();
	head = new;
	while (*format)
	{
		if ((copytolist(&format, new)) == -1)
			return (NULL);
		if (contains(format, '%'))
		{
			new->next = init_list();
			new = new->next;
		}
		if (format && *format)
		{
			parse_percent(&format, new);
			if (!*format)
				break;
			new->next = init_list();
			new = new->next;
		}		
	}
	return (head);
}

ssize_t		parse_and_print(char *format)
{
	t_print		*list;
	t_print		*temp;

	if (!(list = parse_format(format)))
		return (-1);
	temp = list;
	while (temp)
	{
		if (temp->align)
			printf("align: %i\n", temp->align);
		printf("sign: %i\n", temp->sign);
		printf("space: %i\n", temp->space);
		printf("specformat: %i\n", temp->specformat);
		printf("zero: %i\n", temp->zero);
		printf("width: %d\n", temp->width);
		printf("precision: %d\n", temp->precision);
		printf("typemod: %c\n", temp->typemod);
		printf("doublemod: %d\n", temp->doublemod);
		printf("type: %c\n", temp->type);
		printf("out: %s\n", temp->out);
		printf("-------------------\n");
		temp = temp->next;
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	ssize_t	out;

	out = 0;
	if (!contains((char *)format, '%'))
	{
		out = write(1, format, ft_strlen(format));
		return ((int)out);
	}
	else
	{
		va_start(arg, format);
		out = parse_and_print((char *)format);
		va_end(arg);
		return ((int)out);
	}
}
