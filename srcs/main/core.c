/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:26:28 by mressier          #+#    #+#             */
/*   Updated: 2016/05/26 14:26:29 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_core				*init_core(char **envp)
{
	t_core		*core;

	core = (t_core *)ft_memalloc(sizeof(t_core));
	core->env = create_lst_env_from_environ_var(envp);
	return (core);
}

void				del_core(t_core **core)
{
	if (core && *core)
		del_lst_env(&(*core)->env);
	ft_memdel((void **)core);
}
