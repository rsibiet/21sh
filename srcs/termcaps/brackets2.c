/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 12:49:27 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/02 13:31:51 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include <term.h>
#include "libz.h"

int				control_double_brace(t_cmd *cmd, int pos, int i)
{
	if (pos != 0)
		return (0);
	while (cmd)
	{
		if (cmd->val == '{' && cmd->prev && cmd->prev->val == '{')
			i++;
		cmd = cmd->next;
	}
	if (i > 0)
		return (1);
	return (0);
}

int				control_cmd(t_cmd *cmd, t_link_cmd *ln, int i, int nb)
{
	int		prev;

	prev = 0;
	while (cmd && i++ < ln->len - ln->pos &&
		(cmd->val == ' ' || cmd->val == ';'))
	{
		if (cmd->val == ';')
			nb++;
		cmd = cmd->prev;
	}
	if (nb > 0 && i == ln->len - ln->pos + 1)
		return (1);
	while (cmd && i++ < ln->len - ln->pos + 1)
	{
		if (cmd->val == ';' && cmd->prev && cmd->prev->val == ' ')
			prev++;
		cmd = cmd->prev;
	}
	if (prev > 0)
		return (1);
	return (0);
}

static int		control_if_semicolon(t_cmd *cmd)
{
	tputs(tgetstr("do", NULL), 1, ft_putchar_int);
	tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	ft_putstr_intfd("> ");
	while (cmd)
	{
		if (cmd->val == ';')
			return (1);
		else if (cmd->val == ' ')
			cmd = cmd->prev;
		else
			return (0);
	}
	return (0);
}

void			add_semicolon(t_link_cmd *ln, t_cmd *new, int i)
{
	if (control_if_semicolon(ln->tail->prev) == 0)
	{
		new = ft_cmdnew();
		ln->tail->val = ';';
		ln->tail->next = new;
		new->prev = ln->tail;
		ln->tail = new;
		ln->len++;
	}
	if (i % 2 == 0)
	{
		new = ft_cmdnew();
		ln->tail->val = ' ';
		ln->tail->next = new;
		new->prev = ln->tail;
		ln->tail = new;
		ln->len++;
	}
	ln->curse = ln->len;
	if (ln->del_bt == 0 && i < 2)
		ln->del_bt = ln->len - 2 + i % 2;
	else if (ln->del_be == 0 && i > 1)
		ln->del_be = ln->len - 2 + i % 2;
	ln->pos = ln->len;
}
