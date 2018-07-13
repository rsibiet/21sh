/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remysibiet <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 13:59:09 by remysibiet        #+#    #+#             */
/*   Updated: 2016/06/02 13:31:25 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include <term.h>
#include "libz.h"

static void		prev_add(t_link_cmd *ln, int i)
{
	if (ln->quote[0] == 0 && ln->quote[1] == 0 && ln->quote[2] == 0)
		add_semicolon(ln, NULL, i);
	else
		add_semicolon(ln, NULL, i + 1);
}

static void		brace(t_link_cmd *ln, t_cmd *cmd, int be)
{
	while (cmd && (cmd->val == ' ' || cmd->val == '{'))
	{
		if (cmd && cmd->val == '{' && (cmd->next->val == 0 ||
			cmd->next->val == ';' || cmd->next->val == ' ')
			&& (cmd->prev == NULL || cmd->prev->val == ' '))
			ln->quote[5]++;
		cmd = cmd->next;
	}
	while (cmd && cmd->val != '}' && cmd->val != ';')
		cmd = cmd->next;
	while (cmd && (cmd->val == '}' || cmd->val == ' '))
	{
		if (cmd->val == '}' && (cmd->next->val == 0 || cmd->next->val == ' '
			|| cmd->next->val == ';') && cmd->prev->val == ' ')
			ln->quote[5]--;
		cmd = cmd->next;
	}
	if (cmd && cmd->val == ';')
		brace(ln, cmd->next, be);
	else if (be > 0 && ln->quote[5] > 0 && ln->pos != ln->len)
		prev_add(ln, 2);
}

static void		brackets(t_link_cmd *ln, t_cmd *cmd, int bt)
{
	while (cmd && (cmd->val == ' ' || cmd->val == '('))
	{
		if (cmd && cmd->val == '(')
			ln->quote[3]++;
		cmd = cmd->next;
	}
	while (cmd && cmd->val != ')' && cmd->val != ';')
		cmd = cmd->next;
	while (cmd && (cmd->val == ')' || cmd->val == ' '))
	{
		if (cmd->val == ')')
			ln->quote[3]--;
		cmd = cmd->next;
	}
	if (cmd && cmd->val == ';')
		brackets(ln, cmd->next, bt);
	else if (bt > 0)
		prev_add(ln, 0);
}

static void		del_first_semicolon(t_link_cmd *ln, t_cmd *cmd, int tp)
{
	while (cmd && tp > 0)
	{
		tp--;
		cmd = cmd->next;
	}
	if ((cmd->prev->val == '(' || cmd->prev->val == '{') &&
		(cmd->prev->prev == NULL || cmd->prev->prev->val != cmd->prev->val))
	{
		ln->curse--;
		ln->len--;
		cmd->prev->next = cmd->next;
		cmd->next->prev = cmd->prev;
		ft_cmd_delone(&cmd, cmd);
	}
}

void			bracket_hook_brace(t_link_cmd *ln, int bt, int be, int tp)
{
	ln->quote[3] = 0;
	ln->quote[5] = 0;
	if (control_cmd(ln->tail->prev, ln, 0, 0) == 1)
		tp = 1;
	else
	{
		brackets(ln, ln->head, bt);
		brace(ln, ln->head, be);
	}
	if ((tp == 1 || (be == 0 && bt == 0)) && ln->del_be > 0)
	{
		if (ln->del_be < ln->del_bt)
			ln->del_bt--;
		del_first_semicolon(ln, ln->head, ln->del_be);
	}
	if ((tp == 1 || (bt == 0 && be == 0)) && ln->del_bt > 0)
		del_first_semicolon(ln, ln->head, ln->del_bt);
	if (tp == 1)
		return ;
	ln->quote[3] = bt;
	if (control_double_brace(ln->head, ln->pos, 0) == 0)
		ln->quote[5] = be;
}
