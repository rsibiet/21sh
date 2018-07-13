/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_21sh2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:47:15 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/01 18:28:47 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include <term.h>
#include "ft_sh.h"
#include <stdlib.h>

void			add_backslash_n(t_link_cmd *ln, t_cmd *new)
{
	new = ft_cmdnew();
	ln->tail->val = '\n';
	ln->tail->next = new;
	new->prev = ln->tail;
	ln->tail = new;
	ln->len++;
	ln->curse++;
	ln->pos = ln->len;
}

static void		quotes_21sh3(t_link_cmd *ln)
{
	if (ln->quote[3] < 0 || ln->quote[4] < 0 || ln->quote[5] < 0 ||
		ln->quote[0] == 1 || ln->quote[1] == 1 || ln->quote[2] == 1)
	{
		tputs(tgetstr("do", NULL), 1, ft_putchar_int);
		tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	}
}

static char		*simple_put_command(t_link_cmd *ln, t_cmd *cmd, int i, char *s)
{
	s = ft_strnew(ln->len + 1);
	s[ln->len] = '\0';
	while (cmd)
	{
		s[i++] = cmd->val;
		cmd = cmd->next;
	}
	ft_cmd_del(ln->head);
	ln->head = ft_cmdnew();
	ln->tail = ln->head;
	ln->curse = 0;
	ln->len = 0;
	return (s);
}

void			quotes_21sh2(t_link_cmd *ln, t_link_hist *lh, char *s)
{
	quotes_21sh3(ln);
	if (ln->quote[3] < 0 || ln->quote[4] < 0 || ln->quote[5] < 0)
	{
		if (ln->quote[3] < 0)
			set_perror("`)'", PARSING_ERROR);
		else if (ln->quote[4] < 0)
			set_perror("`]'", PARSING_ERROR);
		else if (ln->quote[5] < 0)
			set_perror("`}'", PARSING_ERROR);
		s = simple_put_command(ln, ln->head, 0, NULL);
		update_historique(lh->head->next, lh, s, NULL);
		ft_perror(SHELL);
		tputs(tgetstr("up", NULL), 1, ft_putchar_int);
	}
	else if (ln->quote[0] == 1)
		ft_putstr_intfd("quote> ");
	else if (ln->quote[1] == 1)
		ft_putstr_intfd("dquote> ");
	else if (ln->quote[2] == 1)
		ft_putstr_intfd("bquote> ");
	else
		bracket_hook_brace(ln, ln->quote[3], ln->quote[5], 0);
}

void			memorize_cmd(t_link_cmd *ln, t_cmd *cmd, int i)
{
	if (ln->tmp != NULL)
		ft_strdel(&(ln->tmp));
	ln->tmp = ft_strnew(ln->len + 1);
	cmd = ln->head;
	while (cmd)
	{
		ln->tmp[i++] = cmd->val;
		cmd = cmd->next;
	}
}
