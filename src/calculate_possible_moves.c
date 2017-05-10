/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_possible_moves.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:18:12 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/09 17:05:52 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	find_next_and_prev(int value, int *before, int *after, int *b_arr)
{
	int		i;
	int		smallest;

	i = 0;
	while (b_arr[i])
		smallest = b_arr[i++];
	if (value > b_arr[0])
	{
		*after = b_arr[0];
		*before = b_arr[--i];
	}
	else if (value < smallest)
	{
		*after = b_arr[--i];
		*before = b_arr[0];
	}
	else
	{
		i = 0;
		while (b_arr[i] > value)
			i++;
		*after = b_arr[i];
		*before = b_arr[i - 1];
	}
}

/*
** Calculate the depth a given value can be inserted into stack b with the stack
** remaining sorted.
*/

static int	find_sb_target_depth(int value, t_swap *sb, int *b_arr)
{
	int		target_depth;
	int		before;
	int		after;

	if (b_arr)
		find_next_and_prev(value, &before, &after, b_arr);
	target_depth = 0;
	while (sb)
	{
		if (value < sb->value)
			return (target_depth);
		sb = sb->next;
		target_depth++;
	}
	return (target_depth);
}

/*
** create_b_value_array finds the start point in the list, this function copys
** the values to the newly created array.
*/

static int	*populate_b_vals(t_swap *stack, int start, int *b_val_arr)
{
	t_swap	*stack_begin;
	int		i;
	int		k;

	i = 0;
	stack_begin = stack;
	while (i < start)
		stack = stack->next;
	k = 0;
	while (stack)
	{
		b_val_arr[k++] = stack->value;
		stack = stack->next;
	}
	stack = stack_begin;
	i = 0;
	while (i++ < start)
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

static int	*create_b_value_array(t_swap *stack, t_tracker *tracker,
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

/*
** This function calculates how much stacks a and/or b will have to rotate to
** before inserting any given piece while keeping b sorted.
*/

void		calculate_possible_moves(t_swap *sa, t_swap *sb, t_tracker *tracker)
{
	int		a_cur_depth;
	int		b_target_depth;
	int		*b_vals_in_order;

	a_cur_depth = 0;
	tracker->a_height = stack_length(sa);
	tracker->b_height = stack_length(sb);
	b_vals_in_order = create_b_value_array(sb, tracker, &b_vals_in_order);
	while (sa)
	{
		sa->mov_req_for = a_cur_depth;
		sa->mov_req_bak = tracker->a_height - a_cur_depth;
		b_target_depth = find_sb_target_depth(sa->value, sb, b_vals_in_order);
		sa->sb_req_for = b_target_depth;
		sa->sb_req_bak = b_target_depth - tracker->b_height;
		sa = sa->next;
		a_cur_depth++;
	}
	free(b_vals_in_order);
}
