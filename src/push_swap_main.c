/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 19:28:25 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 20:13:03 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** this funciton chooses the sorting algorithm which will be most effective
** based on the number of integers on the stack.
** Setting the input_cnt on the tracker struct made more sense in the
** read_input() function, but there were too many lines for the norm and it
** didn't make sense to break it apart.
*/

static void		sort_selection(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	tracker->input_cnt = stack_length(*sa);
	if (stack_length(*sa) < 10)
		bubbly_sort_stacks(sa, sb, tracker);
	else
		sort_stacks(sa, sb, tracker);
}

/*
** Ah, main: the beginning of everything.
*/

int				main(int argc, char **argv)
{
	t_swap		*sa;
	t_swap		*sb;
	t_tracker	tracker;
	char		**alt_argv;

	ft_bzero(&tracker, sizeof(t_tracker));
	if (argc > 1)
	{
		if ((alt_argv = arg_string_splitter(++argv)))
			sa = read_input(alt_argv, &tracker);
		else
			sa = read_input(argv, &tracker);
		if (!has_duplicate_inputs(sa))
		{
			sb = NULL;
			if (tracker.debug)
				print_stacks(sa, sb, &tracker);
			sort_selection(&sa, &sb, &tracker);
			if (tracker.debug)
				print_log(sa, &tracker);
			if (alt_argv)
				ft_tab_del(&alt_argv);
		}
	}
	return (0);
}
