/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:12:35 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/22 18:29:07 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_printf(const char *format, ...);

int		main(void)
{	
	int i;

	i = 0;
	i = printf("\"%020s\"\n", "str");
	// i = ft_printf("string: %s, digit: %d, and another simbols, and %% and %+-20.50lld");
	i = ft_printf("string: %20.2s, int: %d%020c", "hello world", 1234566, 'a');
	printf("%i\n", i);
	return (0);
}