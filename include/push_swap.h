
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef enum	e_operation
{
	INVALID = 0, SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
}				t_operation;

typedef struct	s_swap
{
	int			value;
	s_swap		*next;
}				t_swap;

t_swap			*read_input(char **av);
int				is_valid(char *arg);
void			print_stack(t_swap *stack);

#endif
