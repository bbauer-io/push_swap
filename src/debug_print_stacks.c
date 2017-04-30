/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 10:00:24 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 20:14:30 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		print_stacks(t_swap *sa, t_swap *sb, t_tracker *tracker)
{
	ft_putstr("Stack A ------------- Stack B\n");
	ft_putstr("-----------   |   -----------\n");
	while (sa || sb)
	{
		if (sa && sb)
			ft_printf("%-11d   |   %11d\n", sa->value, sb->value);
		else if (sa && !sb)
			ft_printf("%-11d   |   %11c\n", sa->value, ' ');
		else if (!sa && sb)
			ft_printf("%11c   |   %11d\n", ' ', sb->value);
		else
		{
			ft_putstr("-----------   |   -----------\n");
			print_log(tracker);
			return ;
		}
		if (sa)
			sa = sa->next;
		if (sb)
			sb = sb->next;
	}
}
