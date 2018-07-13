/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:12:35 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 15:43:37 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_bin				*create_tree(char *cmd)
{
	t_bin		*tree;

	tree = tree_on_semi_colons(cmd);
	tree = tree_on_redir_and_pipe(tree);
	return (tree);
}
