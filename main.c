/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:12:35 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/05 23:53:33 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int		ft_printf(const char *format, ...);

int		main(void)
{	
	int i;
	char *test = "string";
	//uintmax_t j;

	char *str = "\"%hi, %s\"\n";
	// char *param = "hello world";
	i = 0;
	//j = 0;
	//printf("%lu\n", UINTMAX_MAX);
	//j = 18446744073709551615;
	// i = printf("\"%hhi, %s\"\n", out, test);
	// printf("%i\n", i);
	// i = ft_printf("string: %s, digit: %d, and another simbols, and %% and %+-20.50lld");
	// i = 0;
	i = ft_printf(str, 123, test);
	printf("%i\n", i);
	i = printf(str, 123, test);
	printf("%i\n", i);
	system("leaks -quiet test");
    // system("leaks -quiet ft_printf");
	return (0);
}
