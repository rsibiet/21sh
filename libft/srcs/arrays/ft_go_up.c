/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:33:37 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:16:55 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void	ft_go_up(int *tab, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = 0;
}
