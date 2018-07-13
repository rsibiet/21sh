/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:49:42 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:13:34 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void				ft_int_tab_del(int ***tab, size_t nb_line)
{
	size_t	indx_col;

	indx_col = 0;
	while (indx_col < nb_line)
	{
		ft_intdel(&((*tab)[indx_col]));
		indx_col++;
	}
	ft_memdel((void **)tab);
}
