/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:12:35 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/17 23:33:15 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int		ft_printf(const char *format, ...);

int		main(void)
{	
	int i;
	// char *str = "\"%S\"\n";
	//char *str = "% Zoooo";
	//char *test = "string";
	// setlocale(LC_ALL, "");
	// unsigned long long j = 1;
	// char *param = "hello world";
	// i = printf("\"%hhi, %s\"\n", out, test);
	// printf("%i\n", i);
	// i = ft_printf("string: %s, digit: %d, and another simbols, and %% and %+-20.50lld");
	i = 0;
	i = printf("\"%c\"\n", L'�');
	printf("%i\n", i);
	i = 0;
	i = ft_printf("\"%c\"\n", L'�');
	printf("%i\n", i);
	system("leaks -quiet test");
    // system("leaks -quiet ft_printf");
	return (0);
}