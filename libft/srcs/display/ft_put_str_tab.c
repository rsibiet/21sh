/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 11:38:22 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:18:31 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void		ft_put_str_tab(char **tab)
{
	ft_put_str_tab_fd(tab, 1);
}

void		ft_put_str_tab_fd(char **tab, int fd)
{
	int		indx;

	indx = 0;
	while (tab && tab[indx])
	{
		ft_putchar_fd('|', fd);
		ft_putstr_fd(tab[indx], fd);
		ft_putendl_fd("|", fd);
		indx++;
	}
}
