/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 19:28:25 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 21:51:53 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** this funciton chooses the sorting algorithm which will be most effective
** based on the number of integers on the stack.
*/

static void		sort_selection(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	if (stack_length(*sa) < 10)
		bubbly_sort_stacks(sa, sb, tracker);
	else
		sort_stacks(sa, sb, tracker);
}

/*
** Gets the input numbers and saves them to a stack, checks first for space
** separated values, then individual args.
*/

static void		get_input(char **argv, t_swap **sa, t_tracker *tracker)
{
	char		**alt_argv;

	if ((alt_argv = arg_string_splitter(++argv)))
		*sa = read_input(alt_argv, tracker);
	else
		*sa = read_input(argv, tracker);
	if (alt_argv)
		ft_tab_del(&alt_argv);
}

/*
** Ah, main: the beginning of everything.
*/

int				main(int argc, char **argv)
{
	t_swap		*sa;
	t_swap		*sb;
	t_tracker	tracker;

	ft_bzero(&tracker, sizeof(t_tracker));
	if (argc > 1)
	{
		get_input(argv, &sa, &tracker);
		if (!has_duplicate_inputs(sa))
		{
			sb = NULL;
			if (tracker.debug)
				print_stacks(sa, sb, &tracker);
			sort_selection(&sa, &sb, &tracker);
			if (tracker.debug)
				print_log(sa, &tracker);
		}
		stack_free(sa);
	}
	return (0);
}
