/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d_21sh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:21:36 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/01 10:44:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "ft_sh.h"
#include <curses.h>
#include <term.h>
#include <stdlib.h>

void			insert_cmd_tmp(t_link_hist *lh, t_link_cmd *ln, int i)
{
	if (lh->tp != NULL)
	{
		while (lh->tp[i] != '\0')
			insert_char(ln->head, ln, lh->tp[i++], 0);
		ft_strdel(&lh->tp);
	}
}

static void		add_char_ls(t_cmd *cmd, t_link_cmd *ln, t_cmd *new)
{
	new = ft_cmdnew();
	new->val = 'l';
	cmd = new;
	new = ft_cmdnew();
	new->val = 's';
	new->prev = cmd;
	new->next = ln->tail;
	cmd->next = new;
	ln->head = cmd;
}

void			put_command_in_tp(t_link_cmd *ln, t_cmd *cmd, t_link_hist *lh,
					int i)
{
	lh->tp = ft_strnew(ln->len + 1);
	lh->tp[ln->len] = '\0';
	while (cmd)
	{
		lh->tp[i++] = cmd->val;
		cmd = cmd->next;
	}
	ft_cmd_del(ln->head);
	cmd = ft_cmdnew();
	ln->tail = cmd;
	ln->curse = 2;
	ln->len = 2;
	add_char_ls(NULL, ln, NULL);
}

int				ctrl_d(t_link_cmd *ln, t_link_hist *lh)
{
	if (ln->head->val == 0)
	{
		ft_putchar_int('\n');
		exit_shell(0, NULL);
	}
	else if (ln->curse < ln->len)
	{
		tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
		ln->curse++;
		ft_delete_command(ln, 0);
	}
	else if (ln->tail->prev->val == ' ' && ln->pos == 0)
	{
		put_command_in_tp(ln, ln->head, lh, 0);
		return (1);
	}
	return (0);
}
