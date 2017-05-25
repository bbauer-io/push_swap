/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 09:07:33 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 22:10:24 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Frees the stack that has bee read so far if an error is detected, then prints
** an error message and returns NULL to end the program.
*/

static t_swap		*invalid_input_error(t_swap *sa)
{
	stack_free(sa);
	ft_putstr("Error\n");
	return (NULL);
}

/*
** detects and saves any -c or -v (or -cv, -vc) options and saves them. The
** program will error if any other options are used (will be caught by the
** is_valid_input() function).
*/

static int			is_option(char *arg, t_tracker *tracker)
{
	int			i;

	i = 0;
	if (arg && arg[i] == '-')
	{
		while (ft_isalpha(arg[++i]))
			if (arg[i] != 'v' && arg[i] != 'c')
				return (0);
		if (ft_isdigit(arg[i]))
			return (0);
		if (ft_strchr(arg, 'v'))
			tracker->debug = 1;
		if (ft_strchr(arg, 'c'))
			tracker->color = 1;
		return (1);
	}
	return (0);
}

/*
** Reads the list of argument, checks their validity, and saves each in a linked
** list which will represent our stack.
*/

t_swap				*read_input(char **av, t_tracker *tracker)
{
	t_swap		*sa;
	t_swap		*item;
	long		tmp;

	while (is_option(*av, tracker))
		(*av)++;
	sa = (t_swap *)malloc(sizeof(t_swap));
	ft_bzero(sa, sizeof(t_swap));
	tmp = ft_atol(*av);
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (invalid_input_error(sa));
	sa->value = tmp;
	while (*(++av))
		if (!is_option(*av, tracker))
		{
			item = (t_swap *)malloc(sizeof(t_swap));
			ft_bzero(item, sizeof(t_swap));
			tmp = ft_atol(*av);
			if (tmp > INT_MAX || tmp < INT_MIN)
				return (invalid_input_error(sa));
			item->value = tmp;
			stack_append(&sa, item);
		}
	tracker->input_cnt = stack_length(sa);
	return (sa);
}
