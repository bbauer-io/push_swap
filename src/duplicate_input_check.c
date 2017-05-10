#include "../include/push_swap.h"

int			has_duplicate_inputs(t_swap *stack)
{
	t_swap		*selected;

	selected = stack;
	while (selected)
	{
		stack = selected->next;
		while (stack)
		{
			if (selected->value == stack->value)
			{
				ft_putstr("Error\n");
				return (1);
			}
			stack = stack->next;
		}
		selected = selected->next;
	}
	return (0);
}
