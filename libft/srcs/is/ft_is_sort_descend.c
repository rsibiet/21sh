/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort_descend.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 10:35:30 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:20:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int		ft_is_sort_descend(int *tab, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] > tab[i])
			return (0);
		i++;
	}
	return (1);
}
