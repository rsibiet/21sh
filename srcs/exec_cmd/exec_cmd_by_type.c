/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_by_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:43:20 by mressier          #+#    #+#             */
/*   Updated: 2016/04/25 17:43:21 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				exec_cmd_by_type(char **cmd, enum e_type_cmd type, t_core *core)
{
	int		ret;

	ret = -1;
	if (type == BUILT_IN)
		ret = exec_built_in(cmd, core);
	else if (type == OTHER)
	{
		exec_cmd_with_env_paths(cmd, core->env, core->env);
		ft_perror(SHELL);
	}
	else
		ret = -1;
	return (ret);
}
