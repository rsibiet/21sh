/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:41:04 by mressier          #+#    #+#             */
/*   Updated: 2016/05/11 11:41:05 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		del_one_t_bin(t_bin **del)
{
	if (del && *del)
	{
		ft_strdel(&(*del)->cmd);
		ft_memdel((void **)del);
	}
}

void		del_t_bin(t_bin *tree)
{
	t_bin	*cur;
	t_bin	*tmp;

	if (!tree)
		return ;
	cur = tree;
	tmp = cur->right;
	if (tmp)
		del_t_bin(tmp);
	tmp = cur->left;
	if (tmp)
		del_t_bin(tmp);
	del_one_t_bin(&tree);
}

void		del_branch(t_bin *branch)
{
	del_one_t_bin(&branch->left);
	del_one_t_bin(&branch->right);
	branch->left = NULL;
	branch->right = NULL;
}
