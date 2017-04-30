/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 19:28:25 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 19:28:27 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		print_output(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	if (tracker->debug)
	{
		log_operation(RA, tracker);
		print_stacks(*sa, *sb, tracker);
	}
	else
		print_op_code(tracker->current_operation);
}

int			main(int argc, char **argv)
{
	t_swap		*sa;
//	t_swap		*sb;
	t_tracker	tracker;

	ft_bzero(&tracker, sizeof(t_tracker));
	if (argc > 1)
	{
		sa = read_input(++argv, &tracker);
		print_stack(sa);
//		sort_stack(&sa, &sb, &tracker);
		if (tracker.debug)
			print_log(&tracker);
	}
	return (0);
}
