#include "../include/push_swap.h"

int			main(int argc, char **argv)
{
	t_swap	*sa;
//	t_swap	*sb;

	if (argc > 1)
	{
		sa = read_input(++argv);
		print_stack(sa);
//		sort_stack(sa, sb);
	}
	return (0);
}
