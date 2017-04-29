/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 10:59:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/29 10:59:21 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef enum	e_operation
{
	INVALID = 0, SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
}				t_operation;

typedef struct	s_swap
{
	int				value;
	s_swap			*next;
}				t_swap;

typedef struct	s_tracker
{
	t_operation		current_operation;
	int				debug;
	int				color;
	size_t			counter;
	t_swap			*op_log;
}				t_tracker;

/*
** Control Sections
*/

t_swap			*read_input(char **av, t_tracker *tracker);

/*
** Tools
*/

int				is_valid(char *arg);
void			stack_append(t_swap **stack, t_swap *to_add);
int				stack_length(t_swap *stack);

/*
** Basic operations
*/

void			flip_the_lid(t_swap **stack);
void			rotate_backward(t_swap **stack);
void			rotate_forward(t_swap **stack);
void			swap_a_top(t_swap **s1, t_swap **s2);

/*
** Complex operations which are various combinations of basic operations and
** integrate debug options.
*/

void			pa(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			pb(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			sa(t_swap **sa, t_swap **sb,  t_tracker *tracker);
void			sb(t_swap **sa, t_swap **sb,  t_tracker *tracker);
void			ss(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			ra(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			rb(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			rr(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			rra(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			rrb(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			rrr(t_swap **sa, t_swap **sb, t_tracker *tracker);

/*
** Debug / verbose option functions
*/

void			print_stack(t_swap *stack);
void			print_stacks(t_swap *sa, t_swap *sb, t_tracker *tracker);
void			log_operation(int current_op, t_tracker *tracker);

#endif
