/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:12:35 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/24 19:39:55 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);

int		main(void)
{	
	int i;
	// char str[] = ;

	i = 0;
	i = printf("string: %20s, int: %.0d, char%20.%\n", "hello world", 1234);
	printf("%i\n", i);
	// i = ft_printf("string: %s, digit: %d, and another simbols, and %% and %+-20.50lld");
	i = 0;
	i = ft_printf("string: %20s, int: %d, char%20.%\n", "hello world", 1234);
	printf("%i\n", i);
	system("leaks -quiet test");
    // system("leaks -quiet from_git");
	return (0);
}
