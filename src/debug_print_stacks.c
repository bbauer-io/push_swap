/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 10:00:24 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/23 23:00:31 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char		*opcode_to_str(t_operation code)
{
	if (code == SA)
		return (ft_strdup("sa"));
	else if (code == SB)
		return (ft_strdup("sb"));
	else if (code == SS)
		return (ft_strdup("ss"));
	else if (code == PA)
		return (ft_strdup("pa"));
	else if (code == PB)
		return (ft_strdup("pb"));
	else if (code == RA)
		return (ft_strdup("ra"));
	else if (code == RB)
		return (ft_strdup("rb"));
	else if (code == RR)
		return (ft_strdup("rr"));
	else if (code == RRA)
		return (ft_strdup("rra"));
	else if (code == RRB)
		return (ft_strdup("rrb"));
	else if (code == RRR)
		return (ft_strdup("rrr"));
	else
		return (ft_strdup("ERROR"));
}

void		print_stacks(t_swap *sa, t_swap *sb, t_tracker *tracker)
{
	char	*op;

	op = opcode_to_str(tracker->current_operation);
	ft_putstr("Stack A ~~~~~~~~~~~~~ Stack B\n");
	ft_printf("-----------  %3s  -----------\n", op);
	while (sa || sb)
	{
		if (sa && sb)
			ft_printf("%-11d   |   %11d\n", sa->value, sb->value);
		else if (sa && !sb)
			ft_printf("%-11d   |   %11c\n", sa->value, ' ');
		else if (!sa && sb)
			ft_printf("%11c   |   %11d\n", ' ', sb->value);
		if (sa)
			sa = sa->next;
		if (sb)
			sb = sb->next;
	}
	ft_putstr("-----------   |   -----------\n\n");
	if (op)
		ft_strdel(&op);
	return ;
}
