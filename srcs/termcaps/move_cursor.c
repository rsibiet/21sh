/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:17:52 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/02 18:20:59 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "termcaps.h"
#include <curses.h>
#include <term.h>
#include <sys/ioctl.h>

int				ft_isbackslash_n(t_cmd *cmd, t_link_cmd *ln, int i)
{
	while (i < ln->curse)
	{
		cmd = cmd->next;
		i++;
	}
	if (cmd->prev && cmd->prev->val == '\n')
		return (1);
	else if (cmd->next && cmd->next->val == '\n')
		return (2);
	return (0);
}

static int			contain_backslash_n(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->val == '\n')
			return (1);
		cmd = cmd->next;
	}
	return (0);
}

int				get_len_curpr(int i, t_link_cmd *ln)
{
	if (ft_save_lh(NULL, 1)->sig_cl == 2)
		i = 9;
	else if (contain_backslash_n(ln->head) == 1 && ln->pos == 0)
		return (0);
	else if (i == 0)
		i = get_len_prompt();
	else if (ln->quote[0] != 0)
		i = 7;
	else if (ln->quote[1] != 0 || ln->quote[2] != 0)
		i = 8;
	else if (ln->quote[3] > 0 || ln->quote[5] > 0)
		i = 2;
	return (i);
}

void			move_right(t_link_cmd *ln, int i)
{
	ln->curse++;
	i = get_len_curpr(i, ln);
	if ((i + ln->curse - ln->pos) % ln->c == 0)
	{
		tputs(tgetstr("do", NULL), 1, ft_putchar_int);
		tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	}
	else
		tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
}

void			move_cursor(t_link_cmd *ln, char c[3], t_hist **hist,
					t_link_hist *lh)
{
	struct winsize	ws;
	int				i;

	ioctl(0, TIOCGWINSZ, &ws);
	ln->c = ws.ws_col;
	i = ft_isbackslash_n(ln->head, ln, 0);
	if (c[2] == 'A' && *hist != NULL && lh->cur->next != NULL && ln->pos == 0)
		up_historique(ln, NULL, hist, lh);
	else if (c[2] == 'B' && lh->cur->prev != NULL && ln->pos == 0)
		down_historique(ln, NULL, hist, lh);
	else if (c[2] == 'C' && ln->curse < ln->len && i != 2)
		move_right(ln, ln->pos);
	else if (c[2] == 'D' && ln->curse > ln->pos && i != 1)
	{
		ln->curse--;
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
	}
	lh->cur = *hist;
}
