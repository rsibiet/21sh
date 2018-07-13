/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:23:37 by mressier          #+#    #+#             */
/*   Updated: 2016/02/03 11:05:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int		ft_signed_len(long long int nb, size_t base)
{
	if (base < 2 || base > 16)
		return (-1);
	if (nb < 0)
		return ((base == 10 ? 1 : 0) + ft_unsigned_len(-nb, base));
	if (nb < (long long int)base)
		return (1);
	else
		return (1 + ft_signed_len(nb / base, base));
}
