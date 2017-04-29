#include "../include/push_swap.h"

int			main(int argc, char **argv)
{
	t_swap		*sa;
//	t_swap		*sb;
	t_tracker	tracker;

	ft_bzero(&tracker, sizeof(t_tracker));
	if (argc > 1)
	{
		sa = read_input(++argv, &tracker);
		print_stack(sa);
//		sort_stack(&sa, &sb, &tracker);
		if (tracker.debug)
			print_log(&tracker);
	}
	return (0);
}
