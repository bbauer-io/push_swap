/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/17 00:25:22 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	char	*nullstr;
	char	*goodstr = "goodstr";

	nullstr = NULL;
	
	ft_printf("%x\n", -42);
	
	setlocale(LC_ALL, "");
	ft_printf("%S", L"Á±≥\n");

	ft_printf("holy crapola!\n");
	ft_printf("holy crapola %d: shitbats!\n", 2);
	ft_printf("holy crapola %d: %dxtriple shitbats!\n", 3, 3);
	ft_printf("double percentage test %%");
	ft_printf("\nnull string: %s\n", nullstr);
	ft_printf("{%s}", 0);
	ft_printf("\nnull pointer: %p", nullstr);
	ft_printf("\nvalid pointer: %p", goodstr);
	ft_printf("\nsharp null char #: %#c~", 0);

	ft_printf("\n\nPlus tests! OG PF\n");
	printf("+2d: %+2d\n", 50);
	printf("+04d: %+04d\n", 5);
	printf("+4d: %+4d\n", 5);
	printf("+d: %+d\n", 5);
	ft_printf("\nMY ft_printf\n");
	ft_printf("+2d: %+2d\n", 50);
	ft_printf("+04d: %+04d\n", 5);
	ft_printf("+4d: %+4d\n", 5);
	ft_printf("+d: %+d\n", 5);



return (0);
}
