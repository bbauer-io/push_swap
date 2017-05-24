/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_possible_rev_moves.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:18:12 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 11:37:36 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Fills the tmp array with values from stack a, these should be sorted, but the
** smallest won't necessarily be at the beginning.
*/

static void	fill_tmp_arr_values(t_swap *stack, int *tmp_arr)
{
	int		i;

	i = 0;
	while (stack)
	{
		tmp_arr[i++] = stack->value;
		stack = stack->next;
	}
}

/*
** Returns  an array of ints from stack a which is sorted from smallest to
** largest.
*/

static int	*create_a_value_array(t_swap *stack, int **a_val_arr)
{
	int		i;
	int		k;
	int		*tmp_arr;
	int		stack_len;

	stack_len = stack_length(stack);
	if (!(*a_val_arr = (int *)malloc(sizeof(int) * stack_len)))
		return (NULL);
	if (!(tmp_arr = (int *)malloc(sizeof(int) * stack_len)))
		return (NULL);
	ft_bzero(*a_val_arr, (sizeof(int) * stack_len));
	ft_bzero(tmp_arr, (sizeof(int) * stack_len));
	fill_tmp_arr_values(stack, tmp_arr);
	i = ft_smallest_int(tmp_arr, stack_len);
	k = 0;
	while (i < stack_len)
		(*a_val_arr)[k++] = tmp_arr[i++];
	i = 0;
	while (k < stack_len)
		(*a_val_arr)[k++] = tmp_arr[i++];
	return (*a_val_arr);
}

/*
** Finds the values that should precede and follow the current value when it is
** inserted into the list.
*/

static void	find_next(int value, int *after, int *a_arr, int a_len)
{
	int		i;

	i = 0;
	if (value > a_arr[a_len - 1])
		*after = a_arr[0];
	else
	{
		i = 0;
		while (value > a_arr[i])
			i++;
		*after = a_arr[i];
	}
}

/*
** Calculate the depth a given value can be inserted into stack b with the stack
** remaining sorted.
*/

static int	find_sa_target_depth(int value, t_swap *sa, int *a_arr, int a_len)
{
	int		target_depth;
	int		after;

	if (a_arr && a_len > 1)
		find_next(value, &after, a_arr, a_len);
	else if (a_arr)
		after = a_arr[0];
	target_depth = 0;
	while (sa)
	{
		if (after == sa->value)
			return (target_depth);
		sa = sa->next;
		target_depth++;
	}
	return (target_depth);
}

/*
** This function calculates how much stacks a and/or b will have to rotate to
** before inserting any given piece while keeping b sorted.
*/

void		calculate_possible_rev_moves(t_swap *sa, t_swap *sb, t_tracker *tracker)
{
	int		b_cur_depth;
	int		a_target_depth;
	int		*a_vals_in_order;

	b_cur_depth = 0;
	tracker->a_height = stack_length(sa);
	tracker->b_height = stack_length(sb);
	a_vals_in_order = create_a_value_array(sa, &a_vals_in_order);
	while (sb)
	{
		sb->mov_req_for = b_cur_depth;
		sb->mov_req_bak =
				tracker->b_height == 1 ? 0 : tracker->b_height - b_cur_depth;
		a_target_depth = find_sa_target_depth(sb->value, sa, a_vals_in_order,
															tracker->a_height);
		sb->sb_req_for = a_target_depth;
		sb->sb_req_bak = tracker->a_height - a_target_depth;
		sb = sb->next;
		b_cur_depth++;
	}
	free(a_vals_in_order);
}
