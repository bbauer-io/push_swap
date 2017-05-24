/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 10:59:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/23 21:07:21 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef enum	e_operation
{
	INVALID = 0, SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
}				t_operation;

typedef struct	s_swap
{
	int				value;
	int				mov_req_for;
	int				mov_req_bak;
	int				sb_req_for;
	int				sb_req_bak;
	int				moves_req;
	int				best_path_code;
	struct s_swap	*next;
}				t_swap;

typedef struct	s_tracker
{
	t_operation		current_operation;
	int				a_height;
	int				b_height;
	int				debug;
	int				color;
	int				input_cnt;
	size_t			counter;
	t_swap			*op_log;
}				t_tracker;

/*
** Control Sections
*/

t_swap			*read_input(char **av, t_tracker *tracker);
void			sort_stacks(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			calculate_possible_moves(t_swap *sa, t_swap *sb,
													t_tracker *tracker);
t_swap			*find_best_candidate(t_swap *sa);
t_operation		*build_instructions(t_swap *best_candidate, t_operation *ops);
int				*create_b_value_array(t_swap *stack, t_tracker *tracker,
													int **b_val_arr);
void			execute_instruction(t_swap **stack_a, t_swap **stack_b,
										t_tracker *tracker, t_operation op);

/*
** Tools
*/

char			**arg_string_splitter(char **argv);
int				has_duplicate_inputs(t_swap *stack);
int				is_sorted(t_swap *sa);
int				is_valid(char *arg);
void			print_op_code(int code);
void			print_output(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			stack_append(t_swap **stack, t_swap *to_add);
int				stack_length(t_swap *stack);
void			rotate_largest_to_top(t_swap **sa, t_swap **sb,
										t_tracker *tracker);

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
void			sa(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			sb(t_swap **sa, t_swap **sb, t_tracker *tracker);
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

void			print_stacks(t_swap *sa, t_swap *sb, t_tracker *tracker);
void			print_log(t_swap *sa, t_tracker *tracker);
void			log_operation(int current_op, t_tracker *tracker);

#endif
