/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_largest_to_top.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:15:17 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 20:35:43 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int		find_largest(t_swap *sb)
{
	int				largest;
	int				lg_index;
	int				i;

	i = 0;
	lg_index = i;
	largest = sb->value;
	sb = sb->next;
	while (sb)
	{
		i++;
		if (sb->value > largest)
		{
			largest = sb->value;
			lg_index = i;
		}
		sb = sb->next;
	}
	return (lg_index);
}

static void		fill_ops(t_operation *ops, t_operation rx_code, int rx)
{
	int				i;

	i = 0;
	while (i < rx)
	{
		if (rx_code == RRB)
			ops[i++] = RRB;
		else if (rx_code == RB)
			ops[i++] = RB;
	}
}

void			rotate_largest_to_top(t_swap **sa, t_swap **sb,
															t_tracker *tracker)
{
	t_operation		*ops;
	int				i;
	int				lg_index;
	int				rx;
	t_operation		rx_code;

	lg_index = find_largest(*sb);
	if (stack_length(*sb) - lg_index < lg_index)
	{
		rx = stack_length(*sb) - lg_index;
		rx_code = RRB;
	}
	else
	{
		rx = lg_index;
		rx_code = RB;
	}
	ops = (t_operation *)malloc(sizeof(t_operation) * (rx + 1));
	ft_bzero(ops, sizeof(t_operation) * (rx + 1));
	fill_ops(ops, rx_code, rx);
	i = 0;
	while (ops && ops[i])
		execute_instruction(sa, sb, tracker, ops[i++]);
	free(ops);
}
