/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/17 00:02:49 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	ft_printf ("Characters: %c %c \n", 'a', 65);
	ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
	ft_printf ("Preceding with blanks: %10d \n", 1977);
	ft_printf ("Preceding with zeros: %010d \n", 1977);
	ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	ft_printf ("Width trick: %*d \n", 5, 10);
	ft_printf ("%s \n", "A string");
	return (0);
}
