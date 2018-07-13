/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_opt_v_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:25:58 by mressier          #+#    #+#             */
/*   Updated: 2016/04/27 10:26:00 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void			disp_av(char **av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (i)
			ft_putstr("#env ");
		ft_putstr("\t");
		ft_putstr("arg[");
		ft_putnbr(i);
		ft_putstr("]= '");
		ft_putstr(av[i]);
		ft_putstr("'");
		i++;
		if (av[i])
			ft_putchar('\n');
	}
}

void				prompt_opt_v_env(const char *action, const char *arg,
						char **av)
{
	ft_putstr("#env ");
	if (action)
	{
		ft_putstr(action);
		ft_putstr(": ");
	}
	if (arg)
	{
		ft_putstr(arg);
	}
	if (av)
		disp_av(av);
	ft_putstr("\n");
}
