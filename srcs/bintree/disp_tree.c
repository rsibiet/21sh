/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:06:12 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 09:37:55 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void		rec_disp_tree(t_bin *tree, int deep)
{
	ft_putstr("deep : ");
	ft_putnbr(deep);
	ft_putchar(' ');
	if (tree->cmd)
	{
		ft_putchar('|');
		ft_putstr(tree->cmd);
		ft_putchar('|');
	}
	else
		ft_putchar(tree->ope);
	if (tree->node && tree->node->left == tree)
		ft_putstr(" (left)");
	else if (tree->node && tree->node->right == tree)
		ft_putstr(" (right)");
	ft_putchar('\n');
	if (tree->left)
		rec_disp_tree(tree->left, deep + 1);
	if (tree->right)
		rec_disp_tree(tree->right, deep + 1);
}

void			disp_tree(t_bin *tree)
{
	if (tree)
		rec_disp_tree(tree, 0);
}
