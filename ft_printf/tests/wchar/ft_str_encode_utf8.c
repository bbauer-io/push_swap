/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_encode_utf8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:53:16 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/16 16:53:26 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Encodes a string of wchar unicode code points in utf8.
*/

t_utf8			*ft_str_encode_utf8(const wchar_t *wstr)
{
	size_t		i;
	size_t		len;
	wchar_t		c;
	t_utf8		*utf8;

	len = ft_wstrsize_utf8(wstr);
	if (len > 0)
		if ((utf8 = (t_utf8 *)malloc(sizeof(t_utf8) * (len + 1))))
		{
			i = 0;
			while (i < len)
			{
				c = ft_utf8charencode(*wstr);
				i += ft_wctomb(&utf8[i], c);
				wstr++;
			}
			utf8[i] = '\0';
			return (utf8);
		}
	return (NULL);
}
