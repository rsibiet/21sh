/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_end_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:21:15 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/01 12:39:48 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "ft_sh.h"
#include <curses.h>
#include <term.h>
#include <sys/ioctl.h>

void			ctrl_up_down(int pr, char c, t_link_cmd *ln, int nb)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	ln->c = ws.ws_col;
	nb = get_len_curpr(ln->pos, ln);
	if (ln->curse - ln->pos - ln->c >= 0 && c == 65)
	{
		tputs(tgetstr("up", NULL), 1, ft_putchar_int);
		ln->curse -= ln->c;
	}
	else if (ln->curse + ln->c <= ln->len && c == 66)
	{
		tputs(tgetstr("do", NULL), 1, ft_putchar_int);
		tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
		pr = (nb + ln->curse - ln->pos) % ln->c;
		while (pr-- > 0)
			tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
		ln->curse += ln->c;
	}
}

static void		end_key(t_link_cmd *ln, int tp, int j)
{
	int		i;

	i = tp;
	while (i-- > 0)
	{
		tputs(tgetstr("do", NULL), 1, ft_putchar_int);
		if (i == 0)
			ln->curse += ln->c - get_len_prompt();
		else
			ln->curse += ln->c;
	}
	if (tp)
		tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	while (j-- > 0)
	{
		tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
		ln->curse++;
	}
	ln->curse = ln->len;
}

static void		is_subshell(t_link_cmd *ln, int *i, t_cmd *cmd, int *j)
{
	int		tp;

	tp = 0;
	while (tp < 6)
	{
		if (ln->quote[tp++] != 0)
			tp += 6;
	}
	while (cmd && cmd->prev && cmd->val != '\n')
		cmd = cmd->prev;
	if (ft_save_lh(NULL, 1)->sig_cl == 2)
		tp = 9;
	else if (ln->quote[3] > 0 || ln->quote[5] > 0)
		tp = 2;
	if (tp != 7 && tp != 8 && tp != 9 && tp != 2 && cmd && cmd->val != '\n')
		tp = get_len_prompt();
	*i = (ln->len - ln->curse + tp) / ln->c;
	if (tp == 9 && ft_save_lh(NULL, 1)->sig_cl == 0)
		tp--;
	if (*i == 0)
		tp = 0;
	*j = (ln->len - ln->curse + tp) % ln->c;
}

void			home_end_key(t_link_cmd *ln, char c, t_cmd *cmd, int i)
{
	struct winsize	ws;
	int				j;

	j = 0;
	ioctl(0, TIOCGWINSZ, &ws);
	ln->c = ws.ws_col;
	while (i++ < ln->curse && cmd)
		cmd = cmd->next;
	while (ln->curse > ln->pos && cmd && cmd->prev && cmd->prev->val != '\n')
	{
		cmd = cmd->prev;
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
		ln->curse--;
	}
	is_subshell(ln, &i, ln->tail, &j);
	if (c == 70)
		end_key(ln, i, j);
}
