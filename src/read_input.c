#include "../include/push_swap.h"

/*
** Each argument should be an int that goes on the stack. This function checks
** that only a positive or negative int is in the argument and no other chars,
** and no misplaced chars. Returns a 1 if the argument is valid, 0 if not.
*/

int			is_valid(char *arg)
{
	int		i;

	if (*arg == '-')
		arg++;
	i = 0;
	while (ft_isdigit(arg[i]))
		i++;
	if (i > 0 && arg[i] == '\0')
		return (1);
	else
		return (0);
}

/*
** Reads the list of argument, checks their validity, and saves each in a linked
** list which will represent our stack.
*/

t_swap		*read_input_stack(char **av)
{
	t_swap		*sa;
	t_swap		*item;

	if (!is_valid(*av))
		return (NULL);
	sa = (t_swap *)malloc(sizeof(t_swap));
	ft_bzero(sa, sizeof(t_swap));
	sa->value = ft_atoi(*av);
	while (*(++av))
	{
		if (!is_valid(*av))
			return (NULL);
		item = (t_swap *)malloc(sizeof(t_swap));
		ft_bzero(item, sizeof(t_swap));
		item->value = ft_atoi(*av);
		ft_lst_append(&sa, item);
	}
	return (sa);
}
