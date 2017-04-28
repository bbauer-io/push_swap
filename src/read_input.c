#include "../include/push_swap.h"

t_list		*read_input(char **av)
{
	t_list		*sa;
	t_list		*item;

	sa = (t_list *)malloc(sizeof(t_list));
	ft_bzero(sa, sizeof(t_list));
	sa->content_size = ft_atoi(*av);
	while (*(++av))
	{
		item = (t_list *)malloc(sizeof(t_list));
		ft_bzero(item, sizeof(t_list));
		item->content_size = ft_atoi(*av);
		ft_lst_append(&sa, item);
	}
	return (sa);
}
