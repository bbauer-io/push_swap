/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_smallest_to_top.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:15:17 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 20:35:32 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int		find_smallest(t_swap *sa)
{
	int				smallest;
	int				sm_index;
	int				i;

	i = 0;
	sm_index = i;
	smallest = sa->value;
	sa = sa->next;
	while (sa)
	{
		i++;
		if (sa->value < smallest)
		{
			smallest = sa->value;
			sm_index = i;
		}
		sa = sa->next;
	}
	return (sm_index);
}

static void		fill_ops(t_operation *ops, t_operation rx_code, int rx)
{
	int				i;

	i = 0;
	while (i < rx)
	{
		if (rx_code == RRA)
			ops[i++] = RRA;
		else if (rx_code == RA)
			ops[i++] = RA;
	}
}

void			rotate_smallest_to_top(t_swap **sa, t_swap **sb,
															t_tracker *tracker)
{
	t_operation		*ops;
	int				i;
	int				sm_index;
	int				rx;
	t_operation		rx_code;

	sm_index = find_smallest(*sa);
	if (stack_length(*sa) - sm_index < sm_index)
	{
		rx = stack_length(*sa) - sm_index;
		rx_code = RRA;
	}
	else
	{
		rx = sm_index;
		rx_code = RA;
	}
	ops = (t_operation *)malloc(sizeof(t_operation) * (rx + 1));
	ft_bzero(ops, sizeof(t_operation) * (rx + 1));
	fill_ops(ops, rx_code, rx);
	i = 0;
	while (ops && ops[i])
		execute_instruction(sa, sb, tracker, ops[i++]);
	free(ops);
}
