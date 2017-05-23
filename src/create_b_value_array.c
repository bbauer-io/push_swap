/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_b_value_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 09:02:54 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/23 13:34:07 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** create_b_value_array finds the start point in the list, this function copys
** the values to the newly created array.
*/

static int	*populate_b_vals(t_swap *stack, int lg_index, int *b_val_arr)
{
	t_swap	*stack_begin;
	int		i;
	int		k;

	i = 0;
	stack_begin = stack;
	if (lg_index == 0)
		stack = stack->next;
	else
		while (i++ < lg_index)
			stack = stack->next;
	k = 0;
	while (stack)
	{
		b_val_arr[k++] = stack->value;
		stack = stack->next;
	}
	stack = stack_begin;
	i = 0;
	if (lg_index ==  0)
		b_val_arr[k] = stack->value;
	else
		while (i++ < lg_index)
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
	int		lg_index;
	int		largest;

	if (!stack ||
		!(*b_val_arr = (int *)malloc(sizeof(int) * (tracker->b_height + 1))))
		return (NULL);
	ft_bzero(*b_val_arr, (sizeof(int) * (tracker->b_height + 1)));
	i = 0;
	lg_index = 0;
	largest = stack->value;
	stack_begin = stack;
	while (stack)
	{
		i++;
		if (stack->value > largest)
		{
			largest = stack->value;
			lg_index = i;
		}
		stack = stack->next;
	}
	return (populate_b_vals(stack_begin, lg_index, *b_val_arr));
}

