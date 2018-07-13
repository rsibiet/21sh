/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_in_hist2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:58:17 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/02 18:20:26 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "ft_sh.h"
#include <term.h>

void			clear_cmd(t_link_cmd *ln, t_cmd *cmd)
{
	ft_cmd_del(ln->head);
	cmd = ft_cmdnew();
	ln->head = cmd;
	ln->tail = cmd;
	ln->curse = 0;
	ln->len = 0;
	ln->pos = 0;
}

int			ctrl_r_21sh2(t_link_cmd *ln, int i, char c[3])
{
	if (c[0] == '\012' && (c[1] == 0 || c[1] == -1))
	{
		i = 0;
		ct_rx();
		while (ln->search && ln->search[i] != '\0')
			insert_char(ln->head, ln, ln->search[i++], 0);
		if (ln->tmp != NULL)
			ft_strdel(&ln->tmp);
		return (1);
	}
	return (0);
}

void		ct_rx(void)
{
	tputs(tgetstr("do", NULL), 1, ft_putchar_int);
	tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	prompt();
}
