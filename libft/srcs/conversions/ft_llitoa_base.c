/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:54:16 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:17:41 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char	*ft_llitoa_base(long long int nb, size_t base)
{
	size_t					len;
	char					*ret;
	int						mod;
	unsigned long long int	nb_tmp;

	if ((int)(len = ft_signed_len(nb, base)) == -1)
		return (NULL);
	ret = ft_strnew(len);
	if (nb < 0 && base == 10)
		ret[0] = '-';
	nb_tmp = (nb < 0) ? -nb : nb;
	while (nb_tmp > base - 1)
	{
		mod = nb_tmp % base;
		ret[--len] = (mod < 10) ? mod + 48 : mod + 87;
		nb_tmp /= base;
	}
	ret[--len] = (nb_tmp < 10) ? nb_tmp + 48 : nb_tmp + 87;
	return (ret);
}
