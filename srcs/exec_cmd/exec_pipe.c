/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:33:48 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 15:51:24 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int			error(char *str, enum e_error error)
{
	set_perror(str, error);
	return (-1);
}

int					exec_semi_colons(t_bin *branch, t_core *core)
{
	int		ret;

	ret = exec_bin_tree(branch->left, core);
	if (ret != -1)
		return (ret);
	ret = exec_bin_tree(branch->right, core);
	return (ret);
}

static int			check_error(t_bin *branch)
{
	if (branch->left == NULL || (branch->left && branch->left->cmd
			&& branch->left->cmd[0] == 0) || branch->right == NULL
			|| (branch->right && branch->right->cmd
			&& branch->right->cmd[0] == 0))
		return (error("`|'", PARSING_ERROR));
	return (1);
}

int					exec_pipe(t_bin *branch, t_core *core)
{
	int		pid;
	int		ret;

	pid = -1;
	if (check_error(branch) == -1)
		return (-1);
	pid = ft_pipe();
	if (pid == -1)
		return (-1);
	if (pid == CHILD)
	{
		ret = exec_bin_tree(branch->left, core);
		exit(ret);
	}
	if (branch->left && is_an_ope_after(branch->left, DB_REDIR_LEFT))
		wait(NULL);
	ret = exec_bin_tree(branch->right, core);
	wait(NULL);
	ft_end_fork();
	return (-1);
}
