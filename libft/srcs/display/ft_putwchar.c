/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:54:43 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:20:36 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

#define MASK1 (unsigned int)49280
#define MASK2 (unsigned int)14712960
#define MASK3 4034953344u

static int		ft_put2bt(const unsigned int wc)
{
	unsigned char	o1;
	unsigned char	o2;

	o2 = (wc << 26) >> 26;
	o1 = (wc >> 6);
	ft_putchar((MASK1 >> 8) | o1);
	ft_putchar(((MASK1 << 24) >> 24) | o2);
	return (2);
}

static int		ft_put3bt(const unsigned int wc)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;

	o3 = (wc << 26) >> 26;
	o2 = ((wc >> 6) << 26) >> 26;
	o1 = (wc >> 12);
	ft_putchar((MASK2 >> 16) | o1);
	ft_putchar(((MASK2 << 16) >> 24) | o2);
	ft_putchar(((MASK2 << 24) >> 24) | o3);
	return (3);
}

static int		ft_put4bt(const unsigned int wc)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;

	o4 = (wc << 26) >> 26;
	o3 = ((wc >> 6) << 26) >> 26;
	o2 = ((wc >> 12) << 26) >> 26;
	o1 = (wc >> 18);
	ft_putchar((MASK3 >> 24) | o1);
	ft_putchar(((MASK3 << 8) >> 24) | o2);
	ft_putchar(((MASK3 << 16) >> 24) | o3);
	ft_putchar(((MASK3 << 24) >> 24) | o4);
	return (4);
}

int				ft_putwchar(wchar_t wc)
{
	unsigned int	v;
	int				size;

	v = (unsigned int)wc;
	size = ft_unsigned_len(v, 2);
	if (size <= 7)
		ft_putchar((char)v);
	else if (size <= 11)
		return (ft_put2bt(v));
	else if (size <= 16)
		return (ft_put3bt(v));
	else if (size <= 21)
		return (ft_put4bt(v));
	else
		return (-1);
	return (1);
}
