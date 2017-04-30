/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 09:48:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 19:35:18 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Appends one more item to the stack list.
*/

void		stack_append(t_swap **stack, t_swap *to_add)
{
	t_swap	*tmp;

	if (!to_add || !stack)
		return ;
	tmp = *stack;
	if (!*stack)
		*stack = to_add;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = to_add;
	}
}

/*
** Counts the height of the stack (length of a list of t_swaps)
*/

int			stack_length(t_swap *stack)
{
	int		i;

	i = 0;
	if (stack)
		i++;
	while(stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
