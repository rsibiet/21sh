/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:19:11 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/26 15:51:59 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "termcaps.h"

static void		display_tmp(t_link_cmd *ln, int i, t_cmd *new)
{
	ln->head->val = ln->tmp[0];
	ln->curse++;
	ln->len++;
	while (ln->tmp[i] != '\0')
	{
		new = ft_cmdnew();
		new->val = ln->tmp[i++];
		push_back_cmd(ln, new);
		ln->curse++;
		ln->len++;
	}
	new = ft_cmdnew();
	push_back_cmd(ln, new);
	ft_putstr_intfd(ln->tmp);
}

void			up_historique(t_link_cmd *ln, t_cmd *new, t_hist **hist,
					t_link_hist *lh)
{
	int		i;

	i = 0;
	home_end_key(ln, 70, ln->head, 0);
	if (ln->curse > 0 && (*hist)->s == NULL)
		memorize_cmd(ln, ln->head, 0);
	*hist = lh->cur->next;
	del_cmd_hist(ln, ln->head, 0, 0);
	ln->head->val = (*hist)->s[i++];
	ln->curse++;
	ln->len++;
	while ((*hist)->s[i] != '\0')
	{
		new = ft_cmdnew();
		new->val = (*hist)->s[i++];
		push_back_cmd(ln, new);
		ln->curse++;
		ln->len++;
	}
	new = ft_cmdnew();
	push_back_cmd(ln, new);
	ft_putstr_intfd((*hist)->s);
}

void			down_historique(t_link_cmd *ln, t_cmd *new, t_hist **hist,
					t_link_hist *lh)
{
	int		i;

	i = 0;
	home_end_key(ln, 70, ln->head, 0);
	del_cmd_hist(ln, ln->head, 0, 0);
	*hist = lh->cur->prev;
	if (*hist == lh->head && ln->tmp != NULL)
		display_tmp(ln, 1, NULL);
	if (*hist == lh->head)
		return ;
	ln->head->val = (*hist)->s[i++];
	ln->curse++;
	ln->len++;
	while ((*hist)->s[i] != '\0')
	{
		new = ft_cmdnew();
		new->val = (*hist)->s[i++];
		push_back_cmd(ln, new);
		ln->curse++;
		ln->len++;
	}
	new = ft_cmdnew();
	push_back_cmd(ln, new);
	ft_putstr_intfd((*hist)->s);
}
