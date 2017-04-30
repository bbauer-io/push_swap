/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 08:09:40 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 19:32:25 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** shift up all elemnts of stack a by 1. The first element becomes the last one.
*/

void		ra(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	rotate_forward(sa);
	tracker->counter++;
	print_output(sa, sb, tracker);
}

/*
** shift up all elements of stack b by 1. The first element becomes the last one
*/

void		rb(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	rotate_forward(sb);
	tracker->counter++;
	print_output(sa, sb, tracker);
}

/*
** shift up all elements of stack a and b by 1. The first elements become the
** last.
*/

void		rr(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	rotate_forward(sa);
	rotate_forward(sb);
	tracker->counter++;
	print_output(sa, sb, tracker);
}
