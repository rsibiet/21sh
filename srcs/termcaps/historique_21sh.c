/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historique_21sh.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:10:11 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/31 16:57:44 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "libz.h"
#include <stdlib.h>

void		ft_hist_del(t_hist *lst)
{
	while (lst != NULL)
		ft_hist_delone(&lst, lst);
}

void		ft_hist_delone(t_hist **lst, t_hist *node)
{
	*lst = node->next;
	ft_strdel(&node->s);
	node->next = NULL;
	node->prev = NULL;
	free(node);
}

t_hist		*ft_histnew(void)
{
	t_hist		*hist;

	hist = (t_hist *)ft_memalloc(sizeof(t_hist));
	ft_bzero(hist, sizeof(t_hist));
	return (hist);
}

void		push_back_lst(t_link_hist *ln, t_hist *new)
{
	if (ln->tail)
		ln->tail->next = new;
	new->prev = ln->tail;
	ln->tail = new;
}
