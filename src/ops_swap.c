/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 08:11:25 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 10:46:55 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** swaps the first two elements at the top of stack a
*/

void		sa(t_swap **sa, t_swap **sb,  t_tracker *tracker)
{
	flip_the_lid(sa);
	tracker->counter++;
	if (tracker->debug)
	{
		log_operation(SA, tracker);
		print_stacks(*sa, *sb, tracker);
	}
	else
		ft_putstr("sa\n");
}

/*
** swaps the first two elements at the top of stack b
*/

void		sb(t_swap **sa, t_swap **sb,  t_tracker *tracker)
{
	flip_the_lid(sb);
	tracker->counter++;
	if (tracker->debug)
	{
		log_operation(SB, tracker);
		print_stacks(*sa, *sb, tracker);
	}
	else
		ft_putstr("sb\n");
}

/*
** swaps the first 2 elements at the stop of stack a, and the first 2 at top of ** stack b.
*/

void		ss(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	flip_the_lid(sa);
	flip_the_lid(sb);
	tracker->counter++;
	if (tracker->debug)
	{
		log_operation(SS, tracker);
		print_stacks(*sa, *sb, tracker);
	}
	else
		ft_putstr("ss\n");
}
