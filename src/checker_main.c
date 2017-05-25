/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 21:38:42 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/25 10:54:50 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Parses input and matches it to an operation code.
*/

static t_operation	match_operation(char *line)
{
	if (ft_strequ(line, "sa"))
		return (SA);
	else if (ft_strequ(line, "sb"))
		return (SB);
	else if (ft_strequ(line, "ss"))
		return (SS);
	else if (ft_strequ(line, "pa"))
		return (PA);
	else if (ft_strequ(line, "pb"))
		return (PB);
	else if (ft_strequ(line, "ra"))
		return (RA);
	else if (ft_strequ(line, "rb"))
		return (RB);
	else if (ft_strequ(line, "rr"))
		return (RR);
	else if (ft_strequ(line, "rra"))
		return (RRA);
	else if (ft_strequ(line, "rrb"))
		return (RRB);
	else if (ft_strequ(line, "rrr"))
		return (RRR);
	else
		return (INVALID);
}

/*
** Manages the parsing and execution of instructions.
*/

static void			do_operations(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	char		*line;
	int			operation;

	operation = 1;
	while (operation != INVALID && get_next_line(0, &line))
	{
		operation = match_operation(line);
		execute_instruction(sa, sb, tracker, operation);
	}
	if (operation == INVALID)
	{
		ft_putstr("Error\n");
		stack_free(*sa);
		exit(0);
	}
}

/*
** Ah, main: the beginning of everything.
*/

int					main(int argc, char **argv)
{
	t_swap		*sa;
	t_swap		*sb;
	t_tracker	tracker;
	char		**alt_argv;

	ft_bzero(&tracker, sizeof(t_tracker));
	tracker.silence = 1;
	if (argc > 1)
	{
		if ((alt_argv = arg_string_splitter(++argv)))
			sa = read_input(alt_argv, &tracker);
		else
			sa = read_input(argv, &tracker);
		if (sa && !has_duplicate_inputs(sa))
		{
			do_operations(&sa, &sb, &tracker);
			if (is_sorted(sa) && sb == NULL)
				ft_putstr("\e[32mOK\e[0m\n");
			else
				ft_putstr("\e[31mKO\e[0m\n");
			if (alt_argv)
				ft_tab_del(&alt_argv);
		}
	}
	return (0);
}
