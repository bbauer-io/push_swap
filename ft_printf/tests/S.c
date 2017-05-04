/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/04 11:26:35 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
/*	ft_printf("%%#08x, 42\n");
	ft_printf("%#08x", 42);
	ft_putstr("\n\n");
	ft_printf("%%.10d, 4242\n");
	ft_printf("%.10d", 4242);
	ft_printf("\n0000004242");
*/

	setlocale(LC_ALL, "en_US.UTF-8");
	printf("printf:%S", L"Á±≥");
//	ft_printf("ft_ptf:%S", L"Á±≥");
	return (0);
}
