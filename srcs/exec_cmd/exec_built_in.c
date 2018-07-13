/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:41:59 by mressier          #+#    #+#             */
/*   Updated: 2016/04/25 17:42:01 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_ft_builtin			*get_bt_functions(void)
{
	t_ft_builtin	*ft_bltin;

	ft_bltin = (t_ft_builtin *)ft_memalloc(sizeof(t_ft_builtin)
		* (NB_BUILTIN + 1));
	ft_bltin[BT_ENV] = ft_env_builtin;
	ft_bltin[BT_SETENV] = ft_setenv_builtin;
	ft_bltin[BT_UNSETENV] = ft_unsetenv_builtin;
	ft_bltin[BT_CD] = ft_cd_builtin;
	return (ft_bltin);
}

static t_lst			*exec_bt(enum e_builtin type, char **cmd, t_lst *env)
{
	t_ft_builtin	*ft_bt;

	ft_bt = get_bt_functions();
	env = (ft_bt[type])(cmd, env);
	ft_memdel((void **)&ft_bt);
	return (env);
}

static int				exec_bt_other(enum e_builtin type,
							char **cmd, t_lst *env)
{
	int		ret;

	ret = -1;
	if (type == BT_HASHTABLE)
		ft_builtin_hashtable(env);
	else if (ft_strequ(cmd[0], EXIT))
		ret = ft_exit_builtin(cmd);
	else
		ft_help_builtin();
	return (ret);
}

int						exec_built_in(char **cmd, t_core *core)
{
	enum e_builtin	type;
	int				ret;

	ret = -1;
	type = get_type_builtin(cmd[0]);
	if (type == BT_OTHER || type == BT_HASHTABLE)
		ret = exec_bt_other(type, cmd, core->env);
	else
		core->env = exec_bt(type, cmd, core->env);
	return (ret);
}
