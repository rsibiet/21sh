/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_21sh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 14:14:19 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/31 16:58:34 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "libz.h"

void		ft_cmd_del(t_cmd *lst)
{
	while (lst != NULL)
		ft_cmd_delone(&lst, lst);
}

void		ft_cmd_delone(t_cmd **lst, t_cmd *node)
{
	if (!node)
		return ;
	if (lst && *lst)
		*lst = node->next;
	ft_bzero(node, sizeof(t_cmd));
	ft_memdel((void **)&node);
}

t_cmd		*ft_cmdnew(void)
{
	t_cmd		*cmd;

	cmd = (t_cmd *)ft_memalloc(sizeof(t_cmd));
	ft_bzero(cmd, sizeof(t_cmd));
	return (cmd);
}

void		push_back_cmd(t_link_cmd *ln, t_cmd *new)
{
	if (ln->tail)
		ln->tail->next = new;
	new->prev = ln->tail;
	ln->tail = new;
}
