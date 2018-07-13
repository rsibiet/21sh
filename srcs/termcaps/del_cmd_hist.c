/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cmd_hist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:58:37 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/26 15:16:08 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "ft_sh.h"
#include <curses.h>
#include <term.h>
#include "libz.h"

static void			del_cmd_hist2(t_link_cmd *ln, int nb)
{
	int			len;

	while (nb > 0)
	{
		tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
		tputs(tgetstr("ce", NULL), 1, ft_putchar_int);
		tputs(tgetstr("up", NULL), 1, ft_putchar_int);
		nb--;
	}
	len = get_len_prompt();
	while (nb++ < len)
		tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
	tputs(tgetstr("ce", NULL), 1, ft_putchar_int);
	ft_cmd_del(ln->head);
	ln->head = ft_cmdnew();
	ln->tail = ln->head;
	ln->len = 0;
	ln->curse = 0;
}

void				del_cmd_hist(t_link_cmd *ln, t_cmd *cmd, int nb, int i)
{
	while (cmd)
	{
		if (cmd->val == '\n' || (i != 0 && (i % ln->c) == 0))
			nb++;
		cmd = cmd->next;
		i++;
	}
	if (nb == 0)
	{
		while (ln->curse > 0)
			ft_delete_command(ln, 0);
	}
	else
		del_cmd_hist2(ln, nb);
}
