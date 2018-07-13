/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_get_sym_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:07:00 by mressier          #+#    #+#             */
/*   Updated: 2016/04/27 15:07:01 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char			*cd_create_dir(const char *cmd, int flag, LST_ENV *env)
{
	char		*curpath;
	char		*tmp;

	curpath = NULL;
	if (cmd[0] == '/' || flag == 'P')
		tmp = ft_strdup(cmd);
	else
	{
		tmp = get_env_elem_content(env, "PWD");
		if (!tmp || ft_is_directory(tmp) == 0)
		{
			ft_strdel(&tmp);
			tmp = ft_get_pwd();
		}
		tmp = create_new_path(&tmp, cmd);
	}
	curpath = cut_dir(tmp);
	ft_strdel(&tmp);
	return (curpath);
}
