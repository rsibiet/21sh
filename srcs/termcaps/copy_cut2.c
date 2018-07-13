/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:55:25 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/13 18:58:46 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include <curses.h>
#include <term.h>
#include "libz.h"
#include <sys/ioctl.h>

static void		display_copy_part2(t_cmd *cmd, t_link_cmd *ln, int i, int nb)
{
	while (i++ < nb)
		cmd = cmd->next;
	while (cmd)
	{
		if (cmd->stat == 1)
			tputs(tgetstr("mr", NULL), 1, ft_putchar_int);
		else
			tputs(tgetstr("me", NULL), 1, ft_putchar_int);
		ft_putchar_int(cmd->val);
		cmd = cmd->next;
	}
	i = 0;
	while (i++ < (ln->len - ln->curse))
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
}

void			display_copy_part(t_link_cmd *ln, int nb, int i)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	ln->c = ws.ws_col;
	home_end_key(ln, 70, ln->head, 0);
	ln->curse = i;
	i = 0;
	while (i < ln->len - nb)
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
		tputs(tgetstr("dc", NULL), 1, ft_putchar_int);
		i++;
	}
	display_copy_part2(ln->head, ln, 0, nb);
}

int				last_backslash_n(t_cmd *cmd, int nb)
{
	while (nb > 0 && cmd->prev && cmd->prev->val != '\n')
	{
		nb--;
		cmd = cmd->prev;
	}
	return (nb);
}
