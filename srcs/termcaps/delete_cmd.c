/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 19:24:12 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/02 18:04:59 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include <curses.h>
#include <term.h>
#include "ft_sh.h"

static void			ft_delete_command_2(t_link_cmd *ln, int i, t_cmd *cmd)
{
	i = ln->curse - 1;
	home_end_key(ln, 0, ln->head, 0);
	tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	ln->curse = i;
	i = 0;
	while (i++ < ln->curse && cmd->next != NULL)
		cmd = cmd->next;
	if (cmd->prev != NULL)
		cmd->prev->next = cmd->next;
	else
		ln->head = cmd->next;
	if (cmd->next == NULL)
		ln->tail = cmd->prev;
	cmd->next->prev = cmd->prev;
	ft_cmd_delone(&cmd, cmd);
}

void				ft_delete_command(t_link_cmd *ln, int i)
{
	int		nb;

	nb = get_len_curpr(ln->pos, ln);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_int);
	if (ln->curse > ln->pos && ft_isbackslash_n(ln->head, ln, 0) == 0)
	{
		ft_delete_command_2(ln, 0, ln->head);
		ln->len--;
		insert_in_quote(ln->tail, 0, 0, ln);
		if ((nb + ln->curse - ln->pos) % ln->c == 0)
		{
			tputs(tgetstr("do", NULL), 1, ft_putchar_int);
			tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
		}
		tputs(tgetstr("dc", NULL), 1, ft_putchar_int);
		i = ln->len;
		while (i-- > ln->curse)
			tputs(tgetstr("le", NULL), 1, ft_putchar_int);
	}
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
}
