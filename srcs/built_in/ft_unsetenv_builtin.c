/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:33:34 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 17:33:35 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_lst				*ft_unsetenv_builtin(char **cmd, t_lst *env)
{
	int		i;

	i = 1;
	while (cmd[i])
	{
		env = del_lst_elem_by_name(env, cmd[i]);
		i++;
	}
	if (i == 1)
	{
		set_perror(NULL, TOO_FEW_ARG);
		ft_perror(UNSETENV);
	}
	return (env);
}
