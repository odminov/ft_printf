/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:30:55 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/03 19:50:40 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_printf(const char *format, ...);

int		main(void)
{
	int i;
	char *str1 = "              ";
	char *str2 = "              ";
	char c;

	if ((c = strcmp(str1, str2)))
		printf("%c\n", c);
	else
		printf("equal\n");
	i = 0;
	i = printf("{%*d}", 0, 0);
	printf("\ni: %d\n", i);
	i = 0;
	i = ft_printf("{%*d}", 0, 0);
	printf("\ni: %d\n", i);
	return (0);
}
