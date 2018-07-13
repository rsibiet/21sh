/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:35:13 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 14:03:22 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void			exec_by_ope_suite(t_bin *branch, t_core *core)
{
	int			ret;

	ret = 0;
	if (branch->ope == C_PIPE)
		ret = exec_pipe(branch, core);
	else if (is_a_redir_char(branch->ope))
		ret = exec_redir(branch, core);
	if (ret == -1)
		exit(1);
}

static int			exec_by_ope(t_bin *branch, t_core *core)
{
	int		pid;

	pid = 0;
	if (branch->ope == SEMI_COLONS)
		return (exec_semi_colons(branch, core));
	else
	{
		if (branch->node == NULL || branch->node->ope == SEMI_COLONS
				|| branch->node->ope == C_PIPE)
			pid = ft_fork();
		if (pid == CHILD)
			exec_by_ope_suite(branch, core);
		if (branch->node == NULL || branch->node->ope == SEMI_COLONS
				|| branch->node->ope == C_PIPE)
		{
			wait(NULL);
			ft_end_fork();
		}
	}
	return (-1);
}

/*
** return -1 : pas d'erreur
*/

int					exec_bin_tree(t_bin *branch, t_core *core)
{
	int			ret;

	ret = -1;
	if (!branch)
		return (ret);
	if (branch->ope != 0)
		ret = exec_by_ope(branch, core);
	else if (branch->cmd)
		ret = handle_cmd(branch, core);
	else
	{
		set_perror(NULL, NULL_CMD);
		return (-1);
	}
	return (ret);
}
