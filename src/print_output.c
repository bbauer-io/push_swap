/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 19:35:25 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/23 22:35:28 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** prints the operation currently being performed.
*/

void		print_op_code(int code)
{
	if (code == SA)
		ft_putstr_fd("sa\n", 1);
	else if (code == SB)
		ft_putstr_fd("sb\n", 1);
	else if (code == SS)
		ft_putstr_fd("ss\n", 1);
	else if (code == PA)
		ft_putstr_fd("pa\n", 1);
	else if (code == PB)
		ft_putstr_fd("pb\n", 1);
	else if (code == RA)
		ft_putstr_fd("ra\n", 1);
	else if (code == RB)
		ft_putstr_fd("rb\n", 1);
	else if (code == RR)
		ft_putstr_fd("rr\n", 1);
	else if (code == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (code == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (code == RRR)
		ft_putstr_fd("rrr\n", 1);
	else
		ft_putstr_fd("ERROR\n", 1);
}

void		print_output(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	if (tracker->debug)
	{
		log_operation(tracker->current_operation, tracker);
		print_stacks(*sa, *sb, tracker);
	}
	else if (!tracker->silence)
		print_op_code(tracker->current_operation);
}


