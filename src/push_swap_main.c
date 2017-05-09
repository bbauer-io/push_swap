/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 19:28:25 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 19:37:09 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			main(int argc, char **argv)
{
	t_swap		*sa;
	t_swap		*sb;
	t_tracker	tracker;

	ft_bzero(&tracker, sizeof(t_tracker));
	if (argc > 1)
	{
		sa = read_input(++argv, &tracker);
		print_stack(sa);
		sort_stacks(&sa, &sb, &tracker);
		if (tracker.debug)
			print_log(&tracker);
	}
	return (0);
}
