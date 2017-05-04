/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/04 15:15:42 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <stdio.h>

int		main(void)
{
	int		ret;


	setlocale(LC_ALL, "");
	ft_printf("ft_printf WCHARS:\n");

	ret = ft_printf("%hhC, %hhC", 0, L'米');
	ft_printf("\n%d", ret);
	ft_printf("\n");
	ret = ft_printf("%hhS, %hhS", 0, L"米米");
	ft_printf("\n%d", ret);
	ft_printf("\n");

	printf("printf WCHARS:\n");
	ret = printf("%hhC, %hhC", 0, L'米');
	printf("\n%d", ret);
	printf("\n");
	ret = printf("%hhS, %hhS", 0, L"米米");
	printf("\n%d", ret);
	printf("\n");
return (0);
}
