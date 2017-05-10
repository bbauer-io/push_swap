/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string_splitter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:20:59 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/09 15:41:28 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char		**build_alt_argv(char **argv, int import_index, int av_len)
{
	char	**alt_argv;
	char	**tmp;
	int		i;

	alt_argv = ft_strtok(argv[import_index], " ");
	i = 0;
	while (i < av_len && argv[i])
	{
		if (i != import_index)
		{
			tmp = ft_tab_add_one(alt_argv, argv[i]);
			free(alt_argv);
			alt_argv = tmp;
		}
		i++;
	}
	return (alt_argv);
}

char			**arg_string_splitter(char **argv)
{
	int		i;
	int		av_len;

	av_len = ft_tab_len(argv);
	i = 0;
	while (argv && argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			return (build_alt_argv(argv, i, av_len));
		i++;
	}
	return (NULL);
}
