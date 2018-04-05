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
	if ((list->sign || list->space) && (list->type != 'u' && list->type != 'U'))
		add = 1;
	if (list->width > (int)ft_strlen(out) + add)
	{
		if (list->zero)
		{
			temp = proc_width(list, out, (int)ft_strlen(out), '0', add);
			out = ft_strjoin(prefix, temp);
		}
		else
		{
			out = ft_strjoin(prefix, out);
			temp = out;
			out = proc_width(list, out, (int)ft_strlen(out), ' ', 0);			
		}		
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

static void		delete_minus(char **src)
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

static void		set_prefix(t_print *list, char *prefix, int count)
{
	if ((list->type != 'u' && list->type != 'U') && list->sign)
	{
		if (count < 0)
			prefix[0] = '-';
		else
			prefix[0] = '+';
	}
	if ((list->type != 'u' && list->type != 'U') && !(list->sign) && (list->space))
	{
		if (count < 0)
			prefix[0] = '-';
		else
			prefix[0] = ' ';
	}
}

static int		check_type(t_print *list, va_list arg, char **out)
{
	unsigned long	u_num;
	signed long		s_num;
	int 			i_num;

	s_num = 0;
	i_num = 0;
	if (((list->type == 'd' || list->type == 'i') && list->typemod == 'l') || list->type == 'D')
	{
		s_num = va_arg(arg, signed long);
		*out = ft_itoa_long(&s_num, 's');
	}
	else if ((list->type == 'u' && list->typemod == 'l') || list->type == 'U')
	{
		u_num = va_arg(arg, unsigned long);
		*out = ft_itoa_long(&u_num, 'u');
	}
	else if (list->type == 'u' && list->typemod == '\0')
	{
		u_num = va_arg(arg, unsigned);
		*out = ft_itoa_long(&u_num, 'u');
	}
	else
	{
		i_num = va_arg(arg, int);
		*out = ft_itoa(i_num);
	}
	if (i_num < 0 || s_num < 0)
		delete_minus(out);
	return ((i_num < 0 || s_num < 0) ? -1 : 1);
}

int			processing_number(t_print *list, va_list arg)
{
	char	*out;
	char	*prefix;
	int		sign;

	prefix = ft_strnew(11);
	sign = check_type(list, arg, &out);
	set_prefix(list, prefix, sign);
	if (!(list->out = process_int_precision(list, &out, prefix)))
		return (-1);
	free(prefix);
	if (list->width > (int)ft_strlen(out))
		free(out);
	return (1);
}
