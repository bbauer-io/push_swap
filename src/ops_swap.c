/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 08:11:25 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 19:38:51 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** swaps the first two elements at the top of stack a
*/

void		sa(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	flip_the_lid(sa);
	tracker->counter++;
	tracker->current_operation = SA;
	print_output(sa, sb, tracker);
}

/*
** swaps the first two elements at the top of stack b
*/

void		sb(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	flip_the_lid(sb);
	tracker->counter++;
	tracker->current_operation = SB;
	print_output(sa, sb, tracker);
}

/*
** swaps the first 2 elements at the stop of stack a, and the first 2 at top of ** stack b.
*/

void		ss(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	flip_the_lid(sa);
	flip_the_lid(sb);
	tracker->counter++;
	tracker->current_operation = SS;
	print_output(sa, sb, tracker);
}
