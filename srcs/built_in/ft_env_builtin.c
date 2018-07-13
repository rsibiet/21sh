/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:41:20 by mressier          #+#    #+#             */
/*   Updated: 2016/04/25 17:41:22 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_lst	*get_env_by_flags(int *flags, t_lst *env)
{
	if (flags[ENV_FLAG_I] == 1)
	{
		if (flags[ENV_FLAG_V])
			prompt_opt_v_env(NULL, "clearing environ", NULL);
		return (NULL);
	}
	return (cpy_env(env));
}

static void		del_tmp_var(t_lst **tmp_env, int **flags)
{
	del_lst_env(tmp_env);
	ft_memdel((void **)flags);
}

static void		stc_launch_cmd(char **final_cmd, t_lst *env, t_lst *env_to_send)
{
	int			pid;

	pid = 0;
	pid = ft_fork();
	if (pid == -1)
	{
		set_perror(NULL, FORK_ERROR);
		return ;
	}
	else if (pid == 0)
	{
		exec_cmd_with_env_paths(final_cmd, env, env_to_send);
		set_perror(final_cmd[0], NO_FILE_OR_DIR);
		ft_perror(ENV);
		exit(1);
	}
	wait(NULL);
	ft_end_fork();
}

static void		exec_or_disp(char **split_cmd_end, t_lst *env_to_send,
					t_lst *env, int *flags)
{
	if (split_cmd_end[0])
	{
		if (flags[ENV_FLAG_V])
		{
			prompt_opt_v_env("executing", split_cmd_end[0], NULL);
			prompt_opt_v_env(NULL, NULL, split_cmd_end);
		}
		stc_launch_cmd(split_cmd_end, env, env_to_send);
	}
	else
		ft_disp_env(env_to_send);
}

t_lst			*ft_env_builtin(char **cmd, t_lst *env)
{
	t_lst	*tmp_env;
	int		*flags;
	int		index;

	tmp_env = NULL;
	if (parse_flags_env(cmd, &index, &flags) != -1)
	{
		tmp_env = get_env_by_flags(flags, env);
		if (set_env_with_param_values(cmd, &tmp_env, &index, flags) != -1)
			exec_or_disp(&cmd[index], tmp_env, env, flags);
		else
			ft_perror(ENV);
	}
	del_tmp_var(&tmp_env, &flags);
	return (env);
}
