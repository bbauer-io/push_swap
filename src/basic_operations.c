#include "../include/push_swap.h"

/*
** Swaps the top two items on a stack.
*/

void		flip_the_lid(t_swap **stack)
{
	t_swap		*a;
	t_swap		*b;
	t_swap		*c;

	a = *stack;
	b = (*stack)->next;
	c = (*stack)->next->next;

	*stack = b;
	(*stack)->next = a;
	(*stack)->next->next = c;
	return ;
}

/*
** Takes the top item from S1 and moves it onto the top of S2
*/

void		swap_a_top(t_swap **s1, t_swap **s2)
{
	t_swap		*tmp;

	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
	return ;
}

/*
** Rotates a list forward (top item goes to the bottom)
*/

void		rotate_forward(t_swap **stack)
{
	t_swap		*tmp;
	t_swap		*iter;

	tmp = *stack;
	*stack = (*stack)->next;
	iter = *stack;
	while (iter->next)
		iter = iter->next;
	tmp->next = NULL;
	iter->next = tmp;
	return ;
}

/*
** Rotates a list backward (bottom item is moved to the top)
*/

void		rotate_backward(t_swap **stack)
{
	t_swap		*tmp;
	t_swap		*iter;

	tmp = *stack;
	iter = *stack;
	while (iter->next->next)
		iter = iter->next;
	*stack = iter->next;
	iter->next = NULL;
	(*stack)->next = tmp;
	return ;
}
