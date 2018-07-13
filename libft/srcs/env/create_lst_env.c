/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:38:38 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 12:38:40 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_lst				*create_basic_lst_env(void)
{
	t_lst		*env;
	char		*pwd;
	char		*name;

	env = NULL;
	name = ft_get_host_name();
	pwd = ft_get_pwd();
	env = add_or_modif_env_elem(env, "SHLVL", "0");
	env = add_or_modif_env_elem(env, "HOME", "/");
	env = add_or_modif_env_elem(env, "PWD", pwd);
	ft_strdel(&name);
	ft_strdel(&pwd);
	return (env);
}

t_lst				*create_lst_env_from_environ_var(char **environ)
{
	t_lst	*head_env;
	t_lst	*tmp_lst;
	t_env	*tmp_env;
	int		i;

	i = 0;
	head_env = NULL;
	while (environ[i])
	{
		tmp_env = create_env_elem_by_split(environ[i]);
		tmp_lst = ft_lst_new(tmp_env);
		head_env = ft_lst_add_end(tmp_lst, head_env);
		i++;
	}
	return (head_env);
}
