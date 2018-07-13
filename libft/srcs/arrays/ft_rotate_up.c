/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:30:18 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:17:10 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void	ft_rotate_up(int *tab, size_t size)
{
	int		tmp;

	tmp = tab[0];
	ft_go_up(tab, size);
	tab[size - 1] = tmp;
}