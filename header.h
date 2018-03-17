/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:35:49 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/16 13:35:49 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define TYPES	"sSpdDioOuUxXcC"
# define FLAGS	"#0-+ "
# define MODS	"hljz"
# include "libft/libft.h"
# include <stdlib.h>

typedef struct 		s_print
{
	short int		align;
	short int		sign;
	short int		space;
	short int		specformat;
	short int		zero;
	int				width;
	int				precision;
	char			typemod;
	short int		doublemod;
	char			type;
	char			*out;
	struct s_print	*next;
}					t_print;

void			parse_percent(char **str, t_print *list);
int				contains(char *str, char c);
t_print			*parse_format(char *format);

#endif