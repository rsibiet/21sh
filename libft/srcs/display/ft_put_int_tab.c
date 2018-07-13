/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:49:30 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:18:25 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void	ft_put_int_tab(size_t nb_elem, int *tab)
{
	ft_put_int_tab_fd(nb_elem, tab, 1);
}

void	ft_put_int_tab_fd(size_t nb_elem, int *tab, int fd)
{
	size_t			indx;

	indx = 0;
	while (indx < nb_elem)
	{
		ft_putnbr_fd(tab[indx], fd);
		indx++;
		if (indx < nb_elem)
			ft_putchar_fd(' ', fd);
	}
}
