/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 09:07:33 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/05 11:08:08 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** A test to be sure the argument is not more than INT_MAX
*/

static int			overflows(char *arg)
{
	char	*arg_begin;

	arg_begin = arg;
	if (*arg == '-')
		return (0);
	if (*arg == '+')
		arg++;
	if (*arg > '2')
		return (1);
	else if (*arg == '2' && ft_atoi(arg) < 0)
		return (1);
	else
		return (0);
}

/*
** A test to be sure the argument is not less than INT_MIN
*/

static int			underflows(char *arg)
{
	char	*arg_begin;

	arg_begin = arg;
	if (*arg == '+')
		return (0);
	if (*arg == '-')
		arg++;
	if (*arg > '2')
		return (1);
	else if (*arg == '2' && ft_atoi(arg_begin) > 0)
		return (1);
	else
		return (0);
}

/*
** Each argument should be an int that goes on the stack. This function checks
** that only a positive or negative int is in the argument and no other chars,
** and no misplaced chars. Returns a 1 if the argument is valid, 0 if not.
** Also will check that the number won't overflow the int. (<9 digits or has-----
**
*/

static int			is_valid_input(char *arg)
{
	int		i;
	char	*arg_begin;

	arg_begin = arg;
	if (*arg == '-' || *arg == '+')
		arg++;
	i = 0;
	while (ft_isdigit(arg[i]))
		i++;
	if (i > 0 && arg[i] == '\0' && i < 9)
		return (1);
	else if (i == 10 && !overflows(arg_begin) && !underflows(arg_begin))
		return (1);
	else
		return (0);
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

	while (is_option(*av, tracker))
		(++av);
	if (!is_valid_input(*av))
		return (NULL);
	sa = (t_swap *)malloc(sizeof(t_swap));
	ft_bzero(sa, sizeof(t_swap));
	sa->value = ft_atoi(*av);
	while (*(++av))
	{
		if (is_option(*av, tracker))
			;
		else if (!is_valid_input(*av))
			return (NULL);
		else
		{
			item = (t_swap *)malloc(sizeof(t_swap));
			ft_bzero(item, sizeof(t_swap));
			item->value = ft_atoi(*av);
			stack_append(&sa, item);
		}
	}
	tracker->input_cnt = stack_length(sa);
	return (sa);
}
