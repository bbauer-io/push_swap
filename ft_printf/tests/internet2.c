/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internet2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:22:38 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/03 11:55:01 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	ft_printf("Strings:\n");
	const char* s = "Hello";

	ft_printf("theworst: [%-10.*s]\n", 4, s);
	ft_printf("\t[%10s]\n\t[%-10s]\n\t[%*s]\n\t[%-10.*s]\n\t[%-*.*s]\n",
					s,			s,		10, s,		4, s,		10, 4, s);
	ft_printf("\t[%-10.4s]\n", s);

	ft_printf("\nCharacters:\t%c %%\n", 65);

	ft_printf("\nIntegers:\n");
	ft_printf("Forty Two!: ");
	ft_printf("%08d", 42);
	ft_printf("\nDecimal:\t%i %d %.6i %i %.0i %+i %u\n", 1, 2, 3, 0, 0, 4, -1);
	ft_printf("Hexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
	ft_printf("Octal:\t%o %#o %#o\n", 10, 10, 4);

	ft_printf("\nVariable width control:\n");
	ft_printf("right-justified variable width: '%*c'\n", 5, 'x');
	int r = ft_printf("left-justified variable width : '%*c'\n", -5, 'x');
	ft_printf("(the last printf printed %d characters)\n", r);
	return (0);
}
