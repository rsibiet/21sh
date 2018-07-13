/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:56:29 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:13:42 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int		**ft_int_tab_new(size_t nb_column, size_t nb_line)
{
	int		**tab;
	int		i;

	i = 0;
	tab = ft_memalloc(sizeof(int *) * nb_line);
	while ((size_t)i < nb_line)
	{
		tab[i] = ft_intnew(nb_column);
		i++;
	}
	return (tab);
}
