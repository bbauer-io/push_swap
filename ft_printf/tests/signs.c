/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/03 22:01:38 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
/*	ft_printf("%%0+5d, 42\n");
	ft_printf("%0+5d", 42);
	ft_printf("\n+0042");
*/
	printf("\nprintf:%+03d\n", 1);
	ft_printf("\nme:%+03d", 1);
	return (0);
}
