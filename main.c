/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:12:35 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/27 17:03:48 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);

int		main(void)
{	
	int i;
	// char str[] = ;

	char *str = "\"%+20.10d\"\n";
	// char *param = "hello world";
	i = 0;
	i = printf(str, 123123);
	// printf("%i\n", i);
	// i = ft_printf("string: %s, digit: %d, and another simbols, and %% and %+-20.50lld");
	i = 0;
	i = ft_printf(str, 123123);
	// printf("%i\n", i);
	system("leaks -quiet test");
    // system("leaks -quiet from_git");
	return (0);
}
