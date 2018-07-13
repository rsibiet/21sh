/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:00:33 by mressier          #+#    #+#             */
/*   Updated: 2016/02/03 11:06:51 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int		ft_wcharlen(wchar_t value)
{
	int		nb;

	nb = ft_unsigned_len(value, 2);
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
