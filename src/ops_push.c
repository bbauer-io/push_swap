/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 08:53:40 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 19:30:20 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		pa(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	swap_a_top(sa, sb);
	tracker->counter++;
	print_output(sa, sb, tracker);
}

void		pb(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	swap_a_top(sb, sa);
	tracker->counter++;
	print_output(sa, sb, tracker);
}
