/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:35:49 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/05 13:07:26 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define TYPES	"sSpdDioOuUxXcC%"
# define FLAGS	"#0-+ "
# define MODS	"hljz"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

typedef struct 		s_print
{
	_Bool			align;
	_Bool			sign;
	_Bool			space;
	_Bool			specformat;
	_Bool			zero;
	int				width;
	int				precision;
	_Bool			set_precision;
	char			typemod;
	_Bool			doublemod;
	char			type;
	char			*out;
	struct s_print	*next;
}					t_print;

void			parse_percent(char **str, t_print *list);
int				contains(char *str, char c);
t_print			*parse_format(char *format);
int				valid(char *format);
int				processing_string(t_print *list, va_list arg);
int				processing_percent(t_print *list);
int				processing_number(t_print *list, va_list arg);
int				processing_char(t_print *list, va_list arg);
char			*proc_width(t_print *list, char *src, int len, char c, int add);

#endif