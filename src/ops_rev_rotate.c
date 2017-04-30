/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 09:41:48 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 19:32:01 by bbauer           ###   ########.fr       */
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
	print_output(sa, sb, tracker);
}

/*
** shift down all elements of stack b by 1. The last element becomes the first.
*/

void		rrb(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	rotate_backward(sb);
	tracker->counter++;
	print_output(sa, sb, tracker);
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
	print_output(sa, sb, tracker);
}
