/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 12:13:52 by mressier          #+#    #+#             */
/*   Updated: 2016/05/31 17:00:42 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "ft_sh.h"

int					init_shell(int ac, char **av)
{
	if ((av == NULL && ac != -1) || (ac != 1 && ac != -1))
	{
		ft_puterror("too many argument. Minishell need no arguments.\n");
		return (-1);
	}
	return (1);
}

t_link_hist			init_link_hist(t_hist *hist)
{
	t_link_hist		lh;

	ft_bzero(&lh, sizeof(t_link_hist));
	lh.head = hist;
	lh.tail = hist;
	return (lh);
}
