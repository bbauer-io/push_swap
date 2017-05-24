/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:05:29 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 13:49:54 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void			bubble_sort_stacks(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	int		*tmp_arr;

	while (!is_sorted(*sa))
	{
		if ((*sa)->value > (*sa)->next->value)
		{
			execute_instruction(sa, sb, tracker, SA);
			if (!is_sorted(*sa))
				execute_instruction(sa, sb, tracker, RA);
		}
		else
			execute_instruction(sa, sb, tracker, RRA);
		if (ft_ints_are_sorted(create_a_value_array(*sa, &tmp_arr),
														stack_length(*sa)))
			rotate_smallest_to_top(sa, sb, tracker);
		free(tmp_arr);
	}
}
