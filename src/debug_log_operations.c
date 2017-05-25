/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_log_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 10:42:59 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 22:20:22 by bbauer           ###   ########.fr       */
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

void			print_log(t_swap *sa, t_tracker *tracker)
{
	t_swap		*log;

	log = tracker->op_log;
	while (log)
	{
		print_op_code(log->value);
		log = log->next;
	}
	ft_putnbr(stack_length(tracker->op_log));
	ft_putstr(" total operations.\n");
	if (!is_sorted(sa))
		ft_putstr("\e[31mKO\e[0m\n");
	else
		ft_putstr("\e[32mOK\e[0m\n");
	stack_free(tracker->op_log);
}
