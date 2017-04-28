#include "../include/push_swap.h"

void		print_list(t_list *list)
{
	while (list)
	{
		ft_putnbr(list->content_size);
		ft_putchar('\n');
		list = list->next;
	}
}

int			main(int argc, char **argv)
{
	t_list	*sa;
//	t_list	*sb;

	if (argc > 1)
	{
		sa = read_input(++argv);
		print_list(sa);
	}
	return (0);
}
