/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:12:35 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/24 16:13:54 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);

int		main(void)
{	
	int i;

	i = 0;
	i = printf("string: %20s, int: %.0d, char%20.c\n", "hello world", 124, 'a');
	// i = ft_printf("string: %s, digit: %d, and another simbols, and %% and %+-20.50lld");
	i = ft_printf("string: %20s, int: %.0d, char%20.c", "hello world", 124, 'a');
	printf("%i\n", i - 3);
	system("leaks -quiet test");
	return (0);
}
