/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 08:05:26 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 09:54:20 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Swaps the top two items on a stack.
*/

void		flip_the_lid(t_swap **stack)
{
	t_swap		*a;
	t_swap		*b;
	t_swap		*c;

	if (stack_length(*stack) < 2)
		return ;
	a = *stack;
	b = (*stack)->next;
	c = (*stack)->next->next;
	*stack = b;
	(*stack)->next = a;
	(*stack)->next->next = c;
	return ;
}

/*
** Takes the top item from S2 and moves it onto the top of S1
*/

void		swap_a_top(t_swap **s2, t_swap **s1)
{
	t_swap		*tmp;

	if (!*s1)
		return ;
	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
	return ;
}

/*
** Rotates a list forward (top item goes to the bottom)
*/

void		rotate_forward(t_swap **stack)
{
	t_swap		*tmp;
	t_swap		*iter;

	if (stack_length(*stack) < 2)
	tmp = *stack;
	*stack = (*stack)->next;
	iter = *stack;
	while (iter->next)
		iter = iter->next;
	tmp->next = NULL;
	iter->next = tmp;
	return ;
}

/*
** Rotates a list backward (bottom item is moved to the top)
*/

void		rotate_backward(t_swap **stack)
{
	t_swap		*tmp;
	t_swap		*iter;
	
	if (stack_length(*stack) < 2)
		return ;
	tmp = *stack;
	iter = *stack;
	while (iter->next->next)
		iter = iter->next;
	*stack = iter->next;
	iter->next = NULL;
	(*stack)->next = tmp;
	return ;
}
