/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:32:10 by mressier          #+#    #+#             */
/*   Updated: 2016/05/21 13:10:35 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "termcaps.h"

static t_core		*init_structs(char **environ, t_link_hist *lh,
						t_hist **hist)
{
	t_core			*core;

	core = init_core(environ);
	*hist = ft_histnew();
	*lh = init_link_hist(*hist);
	return (core);
}

int					main(int ac, char **av, char **environ)
{
	t_core			*core;
	char			*cmd;
	t_link_hist		lh;
	t_hist			*hist;

	core = init_structs(environ, &lh, &hist);
	if (init_shell(ac, av) == -1)
		return (1);
	ft_init_signal_handler_g();
	while (1)
	{
		prompt();
		cmd = termcaps_21sh(&lh);
		if (cmd)
			create_tree_and_launch(&cmd, &core);
		else
			break ;
		ft_strdel(&cmd);
	}
	ft_strdel(&cmd);
	exit_shell(0, &core);
	return (0);
}
