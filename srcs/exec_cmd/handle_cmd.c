/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:50:09 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 16:27:47 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int			launch_cmd(char **new_cmd, enum e_type_cmd type,
						t_core *core, t_bin *branch)
{
	int		ret;
	int		pid;

	ret = -1;
	if (type == OTHER && (branch->node == NULL
			|| branch->node->ope == SEMI_COLONS || branch->node->ope == C_PIPE
			|| branch->node->ope == DB_REDIR_LEFT))
	{
		pid = ft_fork();
		if (pid == 0)
		{
			ret = exec_cmd_by_type(new_cmd, type, core);
			exit(1);
		}
		wait(NULL);
		ft_end_fork();
	}
	else
		ret = exec_cmd_by_type(new_cmd, type, core);
	return (ret);
}

static char			**get_split_cmd(char *str, t_lst *env)
{
	char		*tmp;
	char		**split_cmd;
	char		*new_cmd;

	tmp = ft_strdup(str);
	new_cmd = parse_commande(&tmp, env);
	if (new_cmd == NULL)
		return (NULL);
	split_cmd = get_cmd_and_argv(new_cmd);
	ft_strdel(&new_cmd);
	if (split_cmd && split_cmd[0])
		return (split_cmd);
	return (NULL);
}

static int			get_launch_cmd_ret(char **split_cmd, t_core *core,
						t_bin *branch)
{
	enum e_type_cmd	type;
	int				ret;

	type = NOTHING;
	type = get_type_commande(split_cmd[0]);
	ret = launch_cmd(split_cmd, type, core, branch);
	if (ft_strequ(split_cmd[0], "reset") == 1)
		init_shell(-1, NULL);
	return (ret);
}

int					handle_cmd(t_bin *branch, t_core *core)
{
	char			**split_cmd;
	int				ret;

	ret = -1;
	split_cmd = get_split_cmd(branch->cmd, core->env);
	if (split_cmd)
		ret = get_launch_cmd_ret(split_cmd, core, branch);
	ft_str_tab_del(&split_cmd);
	return (ret);
}
