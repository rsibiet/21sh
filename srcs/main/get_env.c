/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:46:22 by mressier          #+#    #+#             */
/*   Updated: 2016/04/25 17:46:24 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_lst		*env_shlvl(t_lst *env)
{
	char	*str_lvl;
	int		lvl;

	lvl = 0;
	str_lvl = get_env_elem_content(env, "SHLVL");
	if (str_lvl)
		lvl = ft_atoi(str_lvl);
	ft_strdel(&str_lvl);
	str_lvl = ft_itoa(lvl + 1);
	modif_env_elem(env, "SHLVL", str_lvl);
	ft_strdel(&str_lvl);
	return (env);
}

static t_lst		*env_home(t_lst *env)
{
	if (get_env_elem(env, "HOME") == NULL)
		env = add_env_elem(env, "HOME", "/");
	return (env);
}

static t_lst		*env_pwd(t_lst *env)
{
	char	*pwd;

	pwd = ft_get_pwd();
	if (get_env_elem(env, "PWD") == NULL)
		env = add_env_elem(env, "PWD", pwd);
	ft_strdel(&pwd);
	return (env);
}

t_lst				*get_env(char **environ)
{
	t_lst	*env;

	env = create_lst_env_from_environ_var(environ);
	if (env == NULL)
		env = create_basic_lst_env();
	env = env_shlvl(env);
	env = env_home(env);
	env = env_pwd(env);
	return (env);
}
