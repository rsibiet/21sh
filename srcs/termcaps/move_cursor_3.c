/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 11:36:06 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/01 12:25:07 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include <curses.h>
#include <term.h>
#include "ft_sh.h"
#include <sys/ioctl.h>

static void		mv_word_l(t_cmd **cmd, t_link_cmd *ln)
{
	*cmd = (*cmd)->prev;
	ln->curse--;
	tputs(tgetstr("le", NULL), 1, ft_putchar_int);
}

static void		mv_word_left(t_cmd *cmd, t_link_cmd *ln)
{
	if (cmd->prev && cmd->prev->val == ' ')
	{
		cmd = cmd->prev;
		while (ln->curse > ln->pos && cmd->val == ' ')
		{
			cmd = cmd->prev;
			ln->curse--;
			tputs(tgetstr("le", NULL), 1, ft_putchar_int);
		}
	}
	else
	{
		while (ln->curse > ln->pos && cmd->prev->val != ' '
			&& cmd->prev->val != '\n')
			mv_word_l(&cmd, ln);
		while (ln->curse > ln->pos && cmd->prev->val == ' '
			&& cmd->prev->val != '\n')
			mv_word_l(&cmd, ln);
	}
}

static void		mv_word_right(t_cmd *cmd, t_link_cmd *ln)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	ln->c = ws.ws_col;
	if (cmd->next && cmd->val == ' ')
	{
		while (ln->curse < ln->len && cmd->val == ' ')
		{
			cmd = cmd->next;
			move_right(ln, ln->pos);
		}
		while (ln->curse < ln->len && cmd->val != ' ' && cmd->val != '\n')
		{
			cmd = cmd->next;
			move_right(ln, ln->pos);
		}
	}
	else
	{
		while (ln->curse < ln->len && cmd->val != ' ' && cmd->val != '\n')
		{
			cmd = cmd->next;
			move_right(ln, ln->pos);
		}
	}
}

void			move_by_word(t_link_cmd *ln, char c, int i, t_cmd *cmd)
{
	if (c == 68)
	{
		while (i++ < ln->curse)
			cmd = cmd->next;
		mv_word_left(cmd, ln);
	}
	else if (c == 67)
	{
		while (i++ < ln->curse)
			cmd = cmd->next;
		mv_word_right(cmd, ln);
	}
}
