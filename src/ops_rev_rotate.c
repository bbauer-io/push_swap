/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 09:41:48 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 10:48:57 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** shift down all elements of stack a by 1. The last element becomes the first.
*/

void		rra(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	rotate_backward(sa);
	tracker->counter++;
	if (tracker->debug)
	{
		log_operation(RRA, tracker);
		print_stacks(*sa, *sb, tracker);
	}
	else
		ft_putstr("rra\n");
}

/*
** shift down all elements of stack b by 1. The last element becomes the first.
*/

void		rrb(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	rotate_backward(sb);
	tracker->counter++;
	if (tracker->debug)
	{
		log_operation(RRB, tracker);
		print_stacks(*sa, *sb, tracker);
	}
	else
		ft_putstr("rrb\n");
}

/*
** shift down all elements of stack a and b by 1. The last elements become the
** first.
*/

void		rrr(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	rotate_backward(sa);
	rotate_backward(sb);
	tracker->counter++;
	if (tracker->debug)
	{
		log_operation(RRR, tracker);
		print_stacks(*sa, *sb, tracker);
	}
	else
		ft_putstr("rrr\n");
}
