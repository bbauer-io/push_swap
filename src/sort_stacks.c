/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 09:52:52 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/05 15:02:04 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void		execute_instruction(t_swap **stack_a, t_swap **stack_b,
										t_tracker *tracker, t_operation op)
{
	if (op == SA)
		sa(stack_a, stack_b, tracker);
	else if (op == SB)
		sb(stack_a, stack_b, tracker);
	else if (op == SS)
		ss(stack_a, stack_b, tracker);
	else if (op == PA)
		pa(stack_a, stack_b, tracker);
	else if (op == PB)
		pb(stack_a, stack_b, tracker);
	else if (op == RA)
		ra(stack_a, stack_b, tracker);
	else if (op == RB)
		rb(stack_a, stack_b, tracker);
	else if (op == RR)
		rr(stack_a, stack_b, tracker);
	else if (op == RRA)
		rra(stack_a, stack_b, tracker);
	else if (op == RRB)
		rrb(stack_a, stack_b, tracker);
	else if (op == RRR)
		rrr(stack_a, stack_b, tracker);
}

/*
** Performs 'pa' until stack b is empty. Is meant to be called when stack a has
** been sorted in reverse into stack b.
*/

static void		complete_sort(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	t_operation		*ops;
	int				i;

	ops = (t_operation *)malloc(sizeof(t_operation) * tracker->input_cnt + 1);
	i = 0;
	while (i < tracker->input_cnt)
		ops[i++] = PA;
	ops[i] = 0;
	i = 0;
	while (ops && ops[i])
		execute_instruction(sa, sb, tracker, ops[i++]);
}

/*
** Returns 1 if the stack is sorted (or there is none to sort), returns 0 if the
** stack is not sorted.
*/

int				is_sorted(t_swap *stack)
{
	int				prev_val;

	if (!stack)
		return (1);
	prev_val = stack->value;
	stack = stack->next;
	while (stack)
	{
		prev_val = stack->value;
		if (prev_val >= stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
** Control center for stack sorting.
*/

void			sort_stacks(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	t_swap			*best_candidate;
	t_operation		*instructions;
	int				i;

	while (*sa && !is_sorted(*sa))
	{
		calculate_possible_moves(*sa, *sb, tracker);
		best_candidate = find_best_candidate(*sa);
		instructions = build_instructions(best_candidate);
		i = 0;
		while (instructions && instructions[i])
			execute_instruction(sa, sb, tracker, instructions[i++]);
		free(instructions);
		if (!*sa)
			complete_sort(sa, sb, tracker);
	}
}
