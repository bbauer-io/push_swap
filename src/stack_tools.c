/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 09:48:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 13:56:13 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** prints the operation currently being performed.
*/

void		print_op_code(int code)
{
	if (code == SA)
		ft_putstr_fd("sa\n", 1);
	else if (code == SB)
		ft_putstr_fd("sb\n", 1);
	else if (code == SS)
		ft_putstr_fd("ss\n", 1);
	else if (code == PA)
		ft_putstr_fd("pa\n", 1);
	else if (code == PB)
		ft_putstr_fd("pb\n", 1);
	else if (code == RA)
		ft_putstr_fd("ra\n", 1);
	else if (code == RB)
		ft_putstr_fd("rb\n", 1);
	else if (code == RR)
		ft_putstr_fd("rr\n", 1);
	else if (code == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (code == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (code == RRR)
		ft_putstr_fd("rrr\n", 1);
	else
		ft_putstr_fd("ERROR\n", 1);
}

/*
** Appends one more item to the stack list.
*/

void		stack_append(t_swap **stack, t_swap *to_add)
{
	t_swap	*tmp;

	if (!to_add || !stack)
		return ;
	tmp = *stack;
	if (!*stack)
		*stack = to_add;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = to_add;
	}
}

/*
** Counts the height of the stack (length of a list of t_swaps)
*/

int			stack_length(t_swap *stack)
{
	int		i;

	i = 0;
	if (stack)
		i++;
	while(stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
