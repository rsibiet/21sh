/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:04:38 by mressier          #+#    #+#             */
/*   Updated: 2016/04/28 18:04:39 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void			put_dir(const char *cmd, const char *dir, t_lst *env)
{
	char	*home;
	char	*tmp_dir;

	if (ft_strequ(cmd, "-"))
	{
		home = get_env_elem_content(env, "HOME");
		if (home != NULL)
		{
			if (ft_strnequ(dir, home, ft_strlen(home)))
			{
				tmp_dir = get_new_path("~", &dir[ft_strlen(home)]);
				ft_putendl(tmp_dir);
				ft_strdel(&tmp_dir);
				ft_strdel(&home);
				return ;
			}
			ft_strdel(&home);
		}
		ft_putendl(dir);
	}
	return ;
}

static char			*get_a_pwd_2(t_lst *env)
{
	char	*pwd;

	pwd = get_env_elem_content(env, "PWD");
	if (pwd == NULL)
		pwd = ft_get_pwd();
	if (ft_strequ(pwd, "."))
		pwd = get_env_elem_content(env, "HOME");
	if (pwd == NULL)
		pwd = ft_strdup("/");
	return (pwd);
}

static char			*get_a_pwd(char *dir, int flag, t_lst *env)
{
	char	*pwd;

	pwd = NULL;
	if (flag != 'P')
		pwd = cd_create_dir(dir, flag, env);
	else
		pwd = ft_get_pwd();
	return (pwd);
}

t_lst				*move_dir(char *cmd_dir, char *dir, t_lst *env, int flag)
{
	char	*pwd;

	pwd = get_a_pwd_2(env);
	if (chdir(dir) == -1)
	{
		ft_strdel(&pwd);
		return (NULL);
	}
	put_dir(cmd_dir, dir, env);
	env = add_or_modif_env_elem(env, "OLDPWD", pwd);
	ft_strdel(&pwd);
	pwd = get_a_pwd(dir, flag, env);
	env = add_or_modif_env_elem(env, "PWD", pwd);
	ft_strdel(&pwd);
	return (env);
}
