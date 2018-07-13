/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:53:50 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:20:11 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Put at most n wchar
*/

#include "libz.h"

int				ft_unblen(unsigned long long int value, int base)
{
	if (value <= (unsigned long long int)base - 1)
		return (1);
	else
		return (1 + ft_unblen(value / base, base));
}

static int		ft_wnblen(wchar_t value)
{
	int		nb;

	nb = ft_unblen(value, 2);
	if (nb <= 7)
		return (1);
	else if (nb <= 11)
		return (2);
	else if (nb <= 16)
		return (3);
	else if (nb <= 21)
		return (4);
	return (-1);
}

void			ft_putnwstr(const wchar_t *ws, int size)
{
	int		n;
	int		tmp;

	tmp = 0;
	n = 0;
	if (ws)
	{
		while (*ws && (n + ft_wnblen(*ws)) <= size)
		{
			if ((tmp = ft_putwchar(*ws++)) == -1)
				ft_puterror("Can't display a char");
			n += tmp;
		}
	}
}
