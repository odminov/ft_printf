/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:39:01 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/11 18:26:42 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "/Users/ahonchar/done/gnl/libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#define TYPES	"sSpdDioOuUxXcC"
#define FLAGS	"#0-+ "
#define MODS	"hljz"

t_print		init_list(void)
{
	t_print		new;

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
	new->sizemod = 0;
	new->type = '\0';
	new->type_exist = 0;
	if (!(new->out = ft_strnew(0)))
		return (NULL);
	new->next = NULL;
	return (new);
}

int			*parse_letter(t_print *current_param, char **format)
{
	if (current_param->type_exist)
		return (1);
	if (ft_strchr(TYPES, **format))
	{
		current_param->type = **format;
		current_param->type_exist = 1;
		return (1);
	}
	if (!current_param->size_mod)
	{
		current_param->typemod = **format;
		if ((**format == (*format)[1]) && (**format == 'h' || **format == 'l'))
		{
			current_param->size_mod = 2;
			return (parse_letter(current_param, ++(*format)));
		}
		++current_param->size_mod;
		return (parse_letter(current_param, ++(*format)));
	}
	return (parse_letter(current_param, ++(*format)));
}

void		parse_flags(t_print *current_param, char **format)
{
	if (**format == '-')
	{
		(current_param->align = 1) && (++(*format));
	}
	else if (**format == '+')
	{
		(current_param->sign = 1) && (++(*format));
	}
	else if (**format == ' ')
	{
		(current_param->space = 1) && (++(*format));
	}
	else if (**format == '#')
	{
		(current_param->specformat = 1) && (++(*format));
	}
	else if (**format == '0')
	{
		(current_param->zero = 1) && (++(*format));
	}
	else
		return ;
}

void		parse_width(t_print *current_param, char **format)
{
	char	nums[11];
	int		i;

	i = 0;
	while (ft_isdigit(**format) && (i < 10))
	{
		nums[i] = **format;
		++i;
		++(*format);
	}
	if (i < 10)
		nums[i] = '\0';
	current_param->width = ft_atoi(nums);
}

void		parse_precision(t_print *current_param, char **format)
{
	/*
	/* start with digit afrer '.'
	*/
}

int			parse_percent(t_print *current_param, char **format)
{
	char	*temp;

	temp = current_param->out;
	current_param->out = ft_strjoin(current_param->out, "%");
	if (!current_param->out)
		return (0);
	++(*format);
	free(temp);
	return (1);
}

int			parse_current_template(t_print *current_param, char **format)
{
	if (ft_isalpha(**format))
	{
		if ((ft_strchr(TYPES, **format)) || (ft_strchr(MODS, **format)))
			return (parse_letter(current_param, format));
		return (0);
	}
	else if (ft_strchr(FLAGS, **format))
		parse_flags(current_param, format);
	else if ((ft_isdigit(**format)) && (**format != '0'))
		parse_width(current_param, format);
	else if (**format == '.' && (++(*format)))
	{
		if (ft_isdigit(**format))
			parse_precision(current_param, format);
		return (0);
	}
	else if (**format == '%')
		return (parse_percent(current_param, format));
	else
		return (0);
	return (parse_current_template(current_param, format));
}

t_print		parse_format(char *format, va_list arg)
{
	t_print	*param_list;
	char	*begin_template;
	char	*temp;

	if (!(param_list = init_list()))
		return (NULL);
	begin_template = NULL;
	if ((begin_template = ft_strchr(format, '%')))
	{
		begin_template = '\0';
		begin_template++;
	}
	temp = param_list->out;
	if (!(param_list->out = ft_strjoin(param_list->out, format)))
		return (NULL);
	free(temp);
	format = begin_template;
	if (format && *format)
		if (!(parse_current_template(param_list, &format)))
			return (NULL);
	if (format && *format)
		param_list->next = parse_format(format);
	return (param_list);
}

ssize_t		parse_and_print(char *format, va_list arg)
{
	t_print	*param_list;
	char	*out;

	param_list = NULL;
	if (!(param_list = parse_format(format, arg)))
		return (-1);
	return (out_result(param_list, out));
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	ssize_t	out;
	char	*percent;

	if (!(percent = ft_strchr(format, '%')))
	{
		out = write(1, format, ft_strlen(format));
		return ((int)out);
	}
	else
	{
		va_start(arg, format);
		out = parse_and_print(format, arg);
		va_end(arg);
		return ((int)out);
	}
}
