/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:34:30 by mressier          #+#    #+#             */
/*   Updated: 2016/05/11 11:34:31 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_bin					*new_t_bin(int ope, char *cmd)
{
	t_bin	*bin_new;

	bin_new = (t_bin *)ft_memalloc(sizeof(t_bin));
	bin_new->ope = ope;
	if (cmd)
		bin_new->cmd = ft_strdup(cmd);
	else
		bin_new->cmd = NULL;
	bin_new->right = NULL;
	bin_new->left = NULL;
	return (bin_new);
}

t_bin					*add_t_bin(t_bin *branch, t_bin *left, t_bin *right)
{
	if (branch)
	{
		branch->left = left;
		branch->right = right;
		if (left)
			branch->left->node = branch;
		if (right)
			branch->right->node = branch;
	}
	return (branch);
}

t_bin					*add_t_bin_end_left(t_bin *branch, t_bin *to_add)
{
	t_bin	*cur;

	if (branch == NULL)
		return (to_add);
	cur = branch;
	while (cur->left)
		cur = cur->left;
	cur->left = to_add;
	if (to_add)
		to_add->node = cur;
	return (branch);
}

t_bin					*add_t_bin_end_right(t_bin *branch, t_bin *to_add)
{
	t_bin	*cur;

	if (branch == NULL)
		return (to_add);
	cur = branch;
	while (cur->right)
		cur = cur->right;
	cur->right = to_add;
	if (to_add)
		to_add->node = cur;
	return (branch);
}
