/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 09:07:33 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/25 11:14:21 by bbauer           ###   ########.fr       */
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
	exit(EXIT_FAILURE);
}

/*
** Mixing digits and letters in a single argument ends the program.
*/

static int			is_valid_input(char *input, t_swap *sa)
{
	int		i;

	if (ft_isalpha(*input))
		invalid_input_error(sa);
	i = 0;
	if (ft_isdigit(input[0]))
		while (input[++i])
			if (!ft_isdigit(input[i]))
				invalid_input_error(sa);
	i = 0;
	if (input[0] == '-' && ft_isalpha(input[1]))
		while (input[++i])
			if (!ft_isalpha(input[i]))
				invalid_input_error(sa);
	i = 0;
	if (input[0] == '-' && ft_isdigit(input[1]))
		while (input[++i])
			if (!ft_isdigit(input[i]))
				invalid_input_error(sa);
	return (1);
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
** Creates a new t_swap item from the current *av.
*/

static t_swap		*create_list_item(char **av)
{
	long		tmp;
	t_swap		*sa;

	sa = (t_swap *)malloc(sizeof(t_swap));
	ft_bzero(sa, sizeof(t_swap));
	tmp = ft_atol(*av);
	if (tmp > INT_MAX || tmp < INT_MIN)
		invalid_input_error(sa);
	sa->value = tmp;
	return (sa);
}

/*
** Reads the list of argument, checks their validity, and saves each in a linked
** list which will represent our stack.
*/

t_swap				*read_input(char **av, t_tracker *tracker)
{
	t_swap		*sa;
	t_swap		*item;

	sa = NULL;
	while (av && *av && is_valid_input(*av, sa) && is_option(*av, tracker))
		av++;
	if (!av || !*av)
		return (NULL);
	sa = create_list_item(av);
	while (*(++av))
		if (!is_option(*av, tracker) && is_valid_input(*av, sa))
		{
			item = create_list_item(av);
			stack_append(&sa, item);
		}
	return (sa);
}
