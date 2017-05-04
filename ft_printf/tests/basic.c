/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/02 09:25:26 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	ft_printf("\n\n%%x, 0\n");
	ft_printf("%x", 0);

	ft_printf("\n\n%%#5.x %%#5.0x, 0, 0\n");
	ft_printf("A:%#5.x %#5.0x", 0, 0);
	printf("\nB:%#5.x %#5.0x", 0, 0);
	return (0);
}