/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 08:53:40 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 10:21:51 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		pa(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	swap_a_top(sa, sb);
	tracker->counter++;
	if (tracker->debug)
	{
		log_operation(PA, tracker);
		print_stacks(*sa, *sb, tracker);
	}
	else
		ft_putstr("pa\n");
}

void		pb(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	swap_a_top(sb, sa);
	tracker->counter++;
	if (tracker->debug)
	{
		log_operation(PB, tracker);
		print_stacks(*sa, *sb, tracker);
	}
	else
		ft_putstr("pb\n");
}
