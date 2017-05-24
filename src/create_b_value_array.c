/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_b_value_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 09:02:54 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/23 20:51:33 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** create_b_value_array finds the start point in the list, this function copys
** the values to the newly created array.
*/

static int	*populate_b_vals(t_swap *stack, int sm_index, int *b_val_arr)
{
	t_swap	*stack_begin;
	int		i;
	int		k;

	i = 0;
	stack_begin = stack;
	if (sm_index == 0)
		stack = stack->next;
	else
		while (i++ < sm_index)
			stack = stack->next;
	k = 0;
	while (stack)
	{
		b_val_arr[k++] = stack->value;
		stack = stack->next;
	}
	stack = stack_begin;
	i = 0;
	if (sm_index ==  0)
		b_val_arr[k] = stack->value;
	else
		while (i++ < sm_index)
		{
			b_val_arr[k++] = stack->value;
			stack = stack->next;
		}
	return (b_val_arr);
}

/*
** creates a list of the values in b, starting from the largest so we can easily
** search for the location to insert our next possible operation.
*/

int			*create_b_value_array(t_swap *stack, t_tracker *tracker,
																int **b_val_arr)
{
	t_swap	*stack_begin;
	int		i;
	int		sm_index;
	int		smallest;

	if (!stack ||
		!(*b_val_arr = (int *)malloc(sizeof(int) * (tracker->b_height + 1))))
		return (NULL);
	ft_bzero(*b_val_arr, (sizeof(int) * (tracker->b_height + 1)));
	i = 0;
	sm_index = 0;
	smallest = stack->value;
	stack_begin = stack;
	while (stack)
	{
		i++;
		if (stack->value < smallest)
		{
			smallest = stack->value;
			sm_index = i;
		}
		stack = stack->next;
	}
	return (populate_b_vals(stack_begin, sm_index, *b_val_arr));
}

