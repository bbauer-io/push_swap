#include "../include/push_swap.h"

void		do_operations(t_list **sa, t_list **sb)
{
	char	*line;
	int		operation;

	operation = 1;
	while (operation != INVALID && get_next_line(0, &line))
		operation = match_operation(line, sa, sb);
}

int			main(int argc, char **argv)
{
	t_list	*sa;
	t_list	*sb;

	sa = NULL;
	sb = NULL;
	if (argc > 1 && (sa = read_input(++argv)) != NULL)
	{
		print_stack(sa);
		do_operations(&sa, &sb);
		if (stack_is_sorted(sa) && sb == NULL)
			ft_putstr("\e[32mOK\e[0m\n");
		else
			ft_putstr("\e[31mKO\e[0m\n");
	}
	else
		ft_putstr("\e[31mError\e[0m\n");
	return (0);
}
