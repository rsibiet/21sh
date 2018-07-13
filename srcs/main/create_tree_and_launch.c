/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree_and_launch.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:42:39 by mressier          #+#    #+#             */
/*   Updated: 2016/05/21 13:22:24 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void				create_tree_and_launch(char **cmd, t_core **core)
{
	t_bin		*tree;
	int			ret;

	tree = create_tree(*cmd);
	if (tree == NULL)
	{
		ft_perror(SHELL);
		ft_strdel(cmd);
		return ;
	}
	ret = exec_bin_tree(tree, *core);
	del_t_bin(tree);
	ft_strdel(cmd);
	if (ret >= 0)
		exit_shell(ret, core);
}
