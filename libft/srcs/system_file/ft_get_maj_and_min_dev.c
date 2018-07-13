/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_maj_and_min_dev.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:08:41 by mressier          #+#    #+#             */
/*   Updated: 2016/02/26 11:08:42 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

static int			ft_major(dev_t dev_id)
{
	return ((dev_id >> 24) & 0xff);
}

static int			ft_minor(dev_t dev_id)
{
	return (dev_id & 0xffffff);
}

int					*ft_get_maj_and_min_dev(dev_t dev_id)
{
	int	*dev_ret;

	dev_ret = (int *)ft_memalloc(sizeof(int) * 2);
	dev_ret[1] = ft_major(dev_id);
	dev_ret[0] = ft_minor(dev_id);
	return (dev_ret);
}
