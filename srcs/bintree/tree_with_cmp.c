/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_on_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:48:01 by mressier          #+#    #+#             */
/*   Updated: 2016/05/17 10:55:44 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_bin		*continue_in_tree(t_bin *branch, int (*cmp)(int))
{
	if (branch && branch->left)
	{
		branch->left = get_char_and_change_it(branch->left, cmp);
		if (branch->left == NULL)
		{
			del_t_bin(branch);
			branch = NULL;
		}
	}
	if (branch && branch->right)
	{
		branch->right = get_char_and_change_it(branch->right, cmp);
		if (branch->right == NULL)
		{
			del_t_bin(branch);
			branch = NULL;
		}
	}
	return (branch);
}

t_bin				*get_char_and_change_it(t_bin *branch, int (*cmp)(int))
{
	int			ope;
	t_bin		*tmp;

	if (!branch)
		return (branch);
	if (branch->cmd)
	{
		ope = str_cmp_separator_char(branch->cmd, cmp);
		if (ope != -1)
		{
			tmp = modif_branch(branch, ope);
			if (tmp == NULL)
				del_t_bin(branch);
			branch = tmp;
		}
	}
	branch = continue_in_tree(branch, cmp);
	return (branch);
}

t_bin				*tree_with_cmp(t_bin *tree, int (*cmp)(int))
{
	if (tree)
		tree = get_char_and_change_it(tree, cmp);
	return (tree);
}
