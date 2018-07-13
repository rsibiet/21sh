/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_on_semi_colons.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:44:24 by mressier          #+#    #+#             */
/*   Updated: 2016/05/29 19:05:53 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_bin				*tree_on_redir_and_pipe(t_bin *tree)
{
	tree = tree_with_cmp(tree, is_a_pipe_char);
	tree = tree_with_cmp(tree, is_a_redir_char);
	return (tree);
}

t_bin				*tree_on_semi_colons(char *cmd)
{
	t_bin		*tree;

	tree = NULL;
	tree = new_t_bin(0, cmd);
	tree = tree_with_cmp(tree, is_a_semi_colons);
	return (tree);
}
