/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_21sh2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:34:15 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/02 13:34:17 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "libz.h"
#include "ft_sh.h"
#include <stdlib.h>
#include <term.h>

char		*put_command(t_link_cmd *link, int i, char *s, t_cmd *cmd)
{
	s = ft_strnew(link->len + 1);
	s[link->len] = '\0';
	while (cmd)
	{
		s[i++] = cmd->val;
		cmd = cmd->next;
	}
	home_end_key(link, 70, link->head, 0);
	ft_putchar_int('\n');
	ft_cmd_del(link->head);
	if (link->tmp != NULL)
		ft_strdel(&(link->tmp));
	link->head = NULL;
	link->tail = NULL;
	return (s);
}

void		update_historique(t_hist *hist, t_link_hist *lh, char *s,
	t_hist *new)
{
	new = ft_histnew();
	new->s = ft_strdup(s);
	lh->head->next = new;
	new->next = hist;
	new->prev = lh->head;
	if (hist != NULL)
		hist->prev = new;
	if (lh->tail == lh->head)
		lh->tail = new;
	if (lh->size_hist == 100)
	{
		hist = lh->tail;
		lh->tail = hist->prev;
		ft_hist_delone(&hist, hist);
		lh->tail->next = NULL;
	}
	else
		lh->size_hist++;
}
