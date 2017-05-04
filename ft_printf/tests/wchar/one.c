/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:39:28 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/15 14:51:24 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new_str)
		return (0);
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
** ft_itoa_base takes a number and returns it as a string in whichever base is
** specified, up to 16.
*/

static void		generate_base_digit_array(char *arr)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		arr[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		arr[i] = i + 'A' - 10;
		i++;
	}
}

/*
** calc_indices calculates the index (in the base_digit_array) which corresponds
** to the character that represents the next digit in base /base/. These indices
** are saved to the indices array.
*/

static int		calc_indices(int *indices, uintmax_t value, int base)
{
	int		i;

	i = 0;
	while (value != 0)
	{
		indices[i++] = value % base;
		value = value / base;
	}
	return (--i);
}

/*
** create_base_str access the digits array at the indices stored in the indices
** array to create the string which will be returned;
*/

static char		*create_base_str(char *digits, int *indices, int i)
{
	int		j;
	char	*result;

	result = (char *)malloc((i + 2) * sizeof(char));
	j = 0;
	while (i >= 0)
		result[j++] = digits[indices[i--]];
	result[j] = '\0';
	return (result);
}

/*
** ft_itoa_base takes a number and returns it as a string in whichever base is
** specified, up to 16.
*/

char			*ft_itoa_base_uintmax(uintmax_t value, int base)
{
	char		base_digits[16];
	int			conversion_index[64];
	int			i;

	if (value == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	generate_base_digit_array(base_digits);
	i = calc_indices(conversion_index, value, base);
	return (create_base_str(base_digits, conversion_index, i));
}

