/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_exec_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:42:54 by mressier          #+#    #+#             */
/*   Updated: 2016/04/25 17:42:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					launch_exec_cmd(const char *cmd, char **argv, t_lst *env)
{
	char	**environ;

	environ = create_str_env(env);
	if (execve(cmd, argv, environ) == -1)
	{
		ft_str_tab_del(&environ);
		return (-1);
	}
	return (1);
}
