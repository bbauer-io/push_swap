/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:51:43 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/14 12:23:05 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns 1 if two strings match exactly.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
