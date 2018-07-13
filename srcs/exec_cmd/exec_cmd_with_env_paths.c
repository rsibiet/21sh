/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:30:24 by mressier          #+#    #+#             */
/*   Updated: 2016/04/21 16:30:25 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int			stc_exec(const char *path_to_test, t_lst *env, char **cmd)
{
	char		*new_path;
	int			ret;

	ret = -1;
	new_path = get_new_path(path_to_test, cmd[0]);
	if (ft_is_exec_file(new_path))
	{
		if (launch_exec_cmd(new_path, cmd, env) == 1)
			ret = 1;
		else
			ret = 0;
	}
	ft_strdel(&new_path);
	return (ret);
}

static int			error_case(char *cmd, int i, int ret)
{
	if (i == 0 && is_a_direct_path(cmd))
	{
		if (ft_is_existing_file(cmd))
			set_perror(cmd, PERM_DENIED);
		else
			set_perror(cmd, NO_FILE_OR_DIR);
		return (1);
	}
	if (ret == 0)
	{
		set_perror(cmd, EXEC_FORMAT_ERROR);
		return (1);
	}
	return (0);
}

static int			try_exec_cmd(char **cmd, char **all_paths,
						t_lst *env)
{
	int		i;
	int		ret;

	i = 0;
	while (all_paths[i])
	{
		if ((ret = stc_exec(all_paths[i], env, cmd)) == 1)
			return (1);
		if (error_case(cmd[0], i, ret))
			break ;
		i++;
	}
	if (i != 0 && ret == -1)
		set_perror(cmd[0], COMMAND_NOT_FOUND);
	return (0);
}

/*
**  	------------------------------------------------------
**  	|						MAIN		         	     |
**  	------------------------------------------------------
*/

int					exec_cmd_with_env_paths(char **command, t_lst *env,
						t_lst *env_to_send)
{
	char	**paths;
	int		ret;

	ret = 0;
	paths = get_valid_paths(env);
	if (paths && command && try_exec_cmd(command, paths, env_to_send))
		ret = 1;
	else if (!paths || !command)
		set_perror(command[0], NO_FILE_OR_DIR);
	ft_str_tab_del(&paths);
	return (ret);
}
