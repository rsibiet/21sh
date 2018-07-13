/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:50:49 by mressier          #+#    #+#             */
/*   Updated: 2016/02/03 11:06:18 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int		ft_unsigned_len(unsigned long long int nb, size_t base)
{
	if (base < 2 || base > 16)
		return (-1);
	if (nb < base)
		return (1);
	else
		return (1 + ft_unsigned_len(nb / base, base));
}
