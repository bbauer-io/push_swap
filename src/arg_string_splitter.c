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

char		**arg_string_splitter(char **argv)
{
	int		i;
	char	**alt_argv;
	int		av_len;
	int		imported_index;

	av_len = ft_tab_len(argv);
	alt_argv = NULL;
	i = 0;
	while (argv && argv[i] && !alt_argv)
	{
		if (ft_strchr(argv[i], ' '))
		{
			alt_argv = ft_strtok(argv[i], " ");
			imported_index = i;
			i = -1;
			while (++i < av_len)
				if (i != imported_index)
					ft_tab_add_one(alt_argv, argv[i]);
			return (alt_argv);
		}
		i++;
	}
	return (NULL);
}
