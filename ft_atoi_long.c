/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:04:04 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/27 18:49:32 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	unsi_ll(unsigned long long *num, char **out, int len)
{
	int i;

	i = 0;
	if (!*num)
		return (NULL);
	while (num > 9)
	{
		
	}
}


char		*ft_atoi_long(void *num, char type)
{
	unsigned long long	u_num;
	long long			s_num;
	int					len;
	char				*out;

	len = 1;
	if (type == 'u')
	{
		u_num = *((unsigned long long *)num);
		while (u_num > 9)
		{
			++len;
			u_num = u_num / 10;
		}
		out = (char *)malloc(sizeof(char *) * len + 1);
		return (unsi_ll((unsigned long long *)num, &out, len));
	}
	s_num = *((long long *)num);
	while (s_num > 9 || s_num < -9)
	{
		++len;
		s_num = s_num / 10;
	}
	out = (char *)malloc(sizeof(char *) * len + 1);
	return (sign_ll((long long *)num, &out, len));
}
