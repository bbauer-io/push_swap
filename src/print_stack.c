#include "../include/push_swap.h"

void		print_stack(t_swap *stack)
{
	while (stack)
	{
		ft_putnbr(stack->value);
		ft_putchar('\n');
		stack = stack->next;
	}
}
