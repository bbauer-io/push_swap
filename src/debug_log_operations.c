/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_log_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 10:42:59 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 11:13:11 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void			log_operation(int current_op, t_tracker *tracker)
{
	t_swap		*new_op;

	new_op = (t_swap *)malloc(sizeof(t_swap));
	ft_bzero(new_op, sizeof(t_swap));
	new_op->value = current_op;
	stack_append(&(tracker->op_log), new_op);
}

static void		print_log_code(int code)
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

void		print_log(t_tracker *tracker)
{
	t_swap		*log;

	log = tracker->op_log;
	while (log)
	{
		print_log_code(log->value);
		log = log->next;
	}
	ft_putnbr(stack_length(tracker->op_log));
	ft_putstr(" total operations.\n");
}
