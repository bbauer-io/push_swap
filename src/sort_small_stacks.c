/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 08:34:17 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 10:57:55 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** My build_instructions() only builds instructions for moving from stack a to,
** stack b, an oversight on my part but easily resolved with this converter
** function now that I've realized I need it. Much easier than rewriting the
** build_instructions.c file.
*/

void			convert_instructions(t_operation *instructions)
{
	while (*instructions)
	{
		if (*instructions == RA)
			*instructions = RB;
		if (*instructions == RB)
			*instructions = RA;
		if (*instructions == RRB)
			*instructions = RRA;
		if (*instructions == RRA)
			*instructions = RRB;
		if (*instructions == PB)
			*instructions = PA;
		instructions++;
	}
}

/*
** Moves all but two items from stack a to stack b
*/

void			split_stacks(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	int				i;
	int				shift;
	t_operation		*shift_ops;

	shift = stack_length(*sa) - 2;
	shift_ops = (t_operation *)malloc(sizeof(t_operation) * (shift + 1));
	i = 0;
	while (shift > 0)
	{
		shift_ops[i++] = PB;
		shift--;
	}
	shift_ops[i] = 0;
	i = 0;
	while (shift_ops && shift_ops[i])
		execute_instruction(sa, sb, tracker, shift_ops[i++]);
	free(shift_ops);
}

/*
** Sorting algorithm for stacks under length of 6.
*/

void			sort_small_stacks(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	int				i;
	t_swap			*best_candidate;
	t_operation		*instructions;

	if (is_sorted(*sa))
		return ;
	split_stacks(sa, sb, tracker);
	if (!is_sorted(*sa))
		execute_instruction(sa, sb, tracker, SA);
	while (sb && *sb)
	{
		calculate_possible_rev_moves(*sa, *sb, tracker);
		best_candidate = find_best_candidate(*sb);
		instructions = build_instructions(best_candidate, instructions);
		convert_instructions(instructions);
		i = 0;
		while (instructions && instructions[i])
			execute_instruction(sa, sb, tracker, instructions[i++]);
		free(instructions);
	}
	rotate_smallest_to_top(sa, sb, tracker);
}
