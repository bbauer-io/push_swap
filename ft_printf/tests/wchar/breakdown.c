/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:11:54 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/16 16:43:41 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

typedef char	t_utf8;

int				ft_wctomb(char *s, wchar_t wc);

char	*ft_itoa_base_uintmax(uintmax_t value, int base);

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned int		i;
	unsigned int		*d;
	unsigned const char	*s;

	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*
** Count number of bits needed to represent a unicode code point.
*/

size_t			ft_wcharbits(wchar_t c)
{
	size_t		i;

	i = 0;
	while (c > 0)
	{
		c = c >> 1;
		i++;
	}
	return (i);
}

/*
** Returns the number of bytes that will be needed to represent a unicode code
** point in UTF-8 format.
*/

size_t			ft_wcharsize_utf8(wchar_t c)
{
	size_t		bits;

	bits = ft_wcharbits(c);
	if (bits <= 7)
		return (1);
	if (bits <= 11)
		return (2);
	if (bits <= 16)
		return (3);
	if (bits <= 21)
		return (4);
	else
		return (0);
}

/*
** Returns the number of bytes needed to represent a string of unicode code
** points after it has been encoded to UTF-8.
*/

size_t			ft_wstrsize_utf8(const wchar_t *wstr)
{
	size_t		size;

	if (!wstr)
		return (0);
	size = 0;
	while (*wstr != '\0')
	{
		size += ft_wcharsize_utf8(*wstr);
		wstr++;
	}
	return (size);
}

/*
** Encodes a wchar_t to UTF-8 or returns the "substitute" character.
*/

wchar_t			ft_utf8charencode(wchar_t c)
{
	size_t				size;
	unsigned int		uc;

	uc = c;
	size = ft_wcharbits(c);
	if (size <= 7)
		return (c);
	if (size <= 11)
	{
		return (((uc >> 6) << 8) | ((uc << 26) >> 26) | 0xC080);
	}
	if (size <= 16)
		return ((((uc >> 12) << 28) >> 12) | (((uc >> 6) << 26) >> 18)
			| ((uc << 26) >> 26) | 0xE08080);
	if (size <= 21)
		return  ((((uc >> 18) << 29) >> 5) | (((uc >> 12) << 26) >> 10)
			| (((uc >> 6) << 26) >> 18) | ((uc << 26) >> 26) | 0xF0808080);
	return (0x1A);
}

/*
** Encodes a string of wchar unicode code points in utf8.
*/

t_utf8			*ft_utf8encode(const wchar_t *wstr)
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

size_t		ft_utf8charsize(wchar_t c)
{
	unsigned int	f;

	f = c;
	if (f <= 0xFF)
		return (1);
	if (f <= 0xFFFF)
		return (2);
	if (f <= 0xFFFFFF)
		return (3);
	if (f <= 0xFFFFFFFF)
		return (4);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	 while (*s)
		 ft_putchar(*s++);
}

int				ft_wctomb(char *s, wchar_t wc)
{
	int			len;
	size_t		i;

	i = 0;
	len = ft_utf8charsize(wc);
	if (len >= 4)
		s[i++] = (0xFF000000 & wc) >> 24;
	if (len >= 3)
		s[i++] = (0xFF0000 & wc) >> 16;
	if (len >= 2)
		s[i++] = (0xFF00 & wc) >> 8;
	if (len >= 1)
		s[i++] = 0xFF & wc;
	return (len);
}
/*
void			ft_putwchr(wchar_t c)
{
	c = ft_utf8charencode(c);
	write(1, &c, sizeof(wchar_t));

	//	write(1, &c, ft_utf8chrsize(c));
}*/

int		main(void)
{
	wchar_t		derp = L'Ξ';

	wchar_t		*str = L"我是一只猫。";
	
	
	char		*a;
	int			i;
	char		*b;

	a = (char *)malloc(sizeof(char) * 6);
	a[0] = 0xCE;
	a[1] = 0x9E;
	a[2] = 0xCE;
	a[3] = 0x9E;
	a[4] = 0xCE;
	a[5] = 0x9E;

	derp = ft_utf8charencode(derp);
	i = 0;
	while (i < 6)
		i += ft_wctomb(&a[i], derp);
	setlocale(LC_ALL, "en_US.UTF-8");

	b = ft_utf8encode(str);
	write(1, a, 6);
	printf("printf (not mine):\t%C\n", L'Ξ');
	write(1, b, 18);
	ft_putchar('\n');
	ft_putstr(b);
}
/*
int             main(void)
{
	char	a[6];

	a[0] = 0xCE;
	a[1] = 0x9E;
	a[2] = 0xCE;
	a[3] = 0x9E;
	a[4] = 0xCE;
	a[5] = 0x9E;

	setlocale(LC_ALL, "en_US.UTF-8");
	write(1, &a, 6);
	printf("printf (not mine):\t%C\n", L'Ξ');
}*/
