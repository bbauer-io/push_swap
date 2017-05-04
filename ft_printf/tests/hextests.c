/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:28:05 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/06 19:30:23 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(void)
{

	ft_printf("\n\nHEX! OG PF\n");
	ft_printf("+04d: %#x\n", INT_MIN);
	ft_printf("+4d: %0x\n", INT_MIN);
	ft_printf("+d: %#X\n", LONG_MIN);



return (0);
}
