/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:12:35 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/10 17:27:15 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);

int		main(void)
{	
	int i;
	//char *test = "string";

	// unsigned long long j = 1;
	char *str = "\"%-d\"\n";
	// char *param = "hello world";
	i = 0;
	// i = printf("\"%hhi, %s\"\n", out, test);
	// printf("%i\n", i);
	// i = ft_printf("string: %s, digit: %d, and another simbols, and %% and %+-20.50lld");
	// i = 0;
	i = printf(str, -2147483648);
	printf("%i\n", i);
	i = ft_printf(str, -2147483648);
	printf("%i\n", i);
	system("leaks -quiet test");
    // system("leaks -quiet ft_printf");
	return (0);
}
