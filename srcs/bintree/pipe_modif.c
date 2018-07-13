/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_modif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:20:32 by mressier          #+#    #+#             */
/*   Updated: 2016/05/17 11:56:15 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_bin		*char_modif(t_bin *branch, int (*cmp)(int), int c)
{
	char			*cmd1;
	char			*cmd2;
	int				index;

	index = str_find_separator_char(branch->cmd, cmp);
	cmd1 = ft_strndup(branch->cmd, index);
	if (branch->cmd[index + 1])
		cmd2 = ft_strdup(&branch->cmd[index + 1]);
	else
		cmd2 = ft_strnew(0);
	ft_str_replace_str(&cmd1, ft_strtrim(cmd1));
	ft_str_replace_str(&cmd2, ft_strtrim(cmd2));
	branch = modif_t_bin(branch, c, NULL);
	branch = add_t_bin(branch, new_t_bin(0, cmd1), new_t_bin(0, cmd2));
	ft_strdel(&cmd1);
	ft_strdel(&cmd2);
	return (branch);
}

static int			is_correct_branch(t_bin *branch)
{
	if (branch && branch->cmd && branch->cmd[0])
		return (1);
	return (0);
}

static t_bin		*del_bad_branch(t_bin *branch)
{
	t_bin	*tmp;

	if (is_correct_branch(branch->left) && is_correct_branch(branch->right))
		return (branch);
	if (is_correct_branch(branch->left))
		tmp = branch->left;
	else
		tmp = branch->right;
	branch = modif_t_bin(branch, 0, ft_strdup(tmp->cmd));
	del_branch(branch);
	return (branch);
}

t_bin				*semi_colons_modif(t_bin *branch)
{
	branch = char_modif(branch, is_a_semi_colons, SEMI_COLONS);
	if (branch)
	{
		if (is_correct_branch(branch->left) || (is_correct_branch(branch->left)
				&& is_correct_branch(branch->right) && branch->node == NULL))
			branch = del_bad_branch(branch);
		else
		{
			set_perror("`;'", PARSING_ERROR);
			del_branch(branch);
			branch = NULL;
		}
	}
	return (branch);
}

t_bin				*pipe_modif(t_bin *branch)
{
	branch = char_modif(branch, is_a_pipe_char, C_PIPE);
	if (is_correct_branch(branch->left) == 0
			|| is_correct_branch(branch->right) == 0)
	{
		set_perror("`|'", PARSING_ERROR);
		del_branch(branch);
		branch = NULL;
	}
	return (branch);
}
