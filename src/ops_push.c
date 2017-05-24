/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 08:53:40 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 09:02:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Push one item from top of stack b to top of stack a.
*/

void		pa(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	swap_a_top(sa, sb);
	tracker->counter++;
	tracker->current_operation = PA;
	print_output(sa, sb, tracker);
}

/*
** Push one item from top of stack a to top of stack b.
*/

void		pb(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	swap_a_top(sb, sa);
	tracker->counter++;
	tracker->current_operation = PB;
	print_output(sa, sb, tracker);
}
