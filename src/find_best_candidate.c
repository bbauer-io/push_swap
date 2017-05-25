/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_candidate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:14:11 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 17:28:26 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Compares the 4 different directions we could rotate the stacks:
** Both going forward, both in reverse, A forward and B in reverse,
** or A in reverse and B forward. Returns a "best path code" so that later
** functions will know which instructions to run for optimal results.
*/

static int	calc_shortest_possible_route(t_swap *sa)
{
	int		attempt[4];

	ft_bzero(attempt, sizeof(int) * 4);
	attempt[0] = MAX(sa->mov_req_for, sa->sb_req_for) + 1;
	attempt[1] = MAX(sa->mov_req_bak, sa->sb_req_bak) + 1;
	attempt[2] = sa->mov_req_for + sa->sb_req_bak + 1;
	attempt[3] = sa->mov_req_bak + sa->sb_req_for + 1;
	sa->best_path_code = ft_smallest_int(attempt, 4);
	return (attempt[sa->best_path_code]);
}

/*
** Compares number of moves required to sort each piece and chooses the one
** that requires the least moves.
*/

t_swap		*find_best_candidate(t_swap *sa)
{
	t_swap	*best_candidate;

	sa->moves_req = calc_shortest_possible_route(sa);
	best_candidate = sa;
	sa = sa->next;
	while (sa)
	{
		sa->moves_req = calc_shortest_possible_route(sa);
		if (sa->moves_req < best_candidate->moves_req)
			best_candidate = sa;
		sa = sa->next;
	}
	return (best_candidate);
}
