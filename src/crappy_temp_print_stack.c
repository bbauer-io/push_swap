/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 09:07:55 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 09:07:56 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		print_stack(t_swap *stack)
{
	while (stack)
	{
		ft_putnbr(stack->value);
		ft_putchar('\n');
		stack = stack->next;
	}
}
