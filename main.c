/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:12:35 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/01 16:42:21 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int		ft_printf(const char *format, ...);

int		main(void)
{
	int	i;

	i = 0;
	i = printf("{%*d}", 0, 0);
	printf("%i\n", i);
	i = 0;
	i = ft_printf("{%*d}", 0, 0);
	printf("%i\n", i);
	system("leaks -quiet test");
	return (0);
}
