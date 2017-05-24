/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:05:29 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 12:32:25 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void			bubble_sort_stacks(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	while (!is_sorted(*sa))
	{
		if ((*sa)->value > (*sa)->next->value)
			execute_instruction(sa, sb, tracker, SA);
		else
			execute_instruction(sa, sb, tracker, RRA);
	}
}
