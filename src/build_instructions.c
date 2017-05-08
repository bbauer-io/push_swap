/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:03:12 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/05 15:10:30 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_operation		*use_rr(t_swap *selected, t_operation *op)
{
	int			i;
	int			rx;

	i = 0;
	op = (t_operation *)malloc(sizeof(t_operation) * (selected->moves_req + 1));
	rx = ABS(selected->mov_req_for - selected->sb_req_for);
	while (i < rx)
		op[i++] = RR;
	rx = MAX(selected->mov_req_for, selected->sb_req_for);
	if (selected->mov_req_for > selected->sb_req_for)
		while (i < rx)
			op[i++] = RA;
	else if (selected->mov_req_for < selected->sb_req_for)
		while (i < rx)
			op[i++] = RB;
	op[i] = PB;
	return (op);
}

t_operation		*build_instructions(t_swap *selected, t_operation *ops)
{
	if (selected->best_path_code == 0)
		return (use_rr(selected, ops));
	else if (selected->best_path_code == 1)
		return (use_rra());
	else if (selected->best_path_code == 2)
		return (use_rra());
	else if (selected->best_path_code == 3)
		return (use_rra());
	else
		return (NULL);
}
