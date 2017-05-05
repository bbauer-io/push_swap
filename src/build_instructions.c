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

t_operation		*build_instructions(t_swap *selected)
{
	if (selected->best_path_code == 0)
		return (use_rra());
	else if (selected->best_path_code == 1)
		return (use_rra());
	else if (selected->best_path_code == 2)
		return (use_rra());
	else if (selected->best_path_code == 3)
		return (use_rra());
	else
		return (NULL);
}
