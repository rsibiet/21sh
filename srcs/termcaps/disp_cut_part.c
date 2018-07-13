/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_cut_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:20:02 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/31 17:20:36 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include <curses.h>
#include <term.h>

void			display_cut_part(t_cmd *cmd, t_link_cmd *ln, int i)
{
	while (ln->len + 1 > ln->curse)
	{
		ln->curse++;
		tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
	}
	while (cmd && i != 1)
	{
		if (cmd->stat == 0 && (cmd->prev == NULL || cmd->prev->stat == 1))
			i = 1;
		cmd = cmd->prev;
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
		ln->curse--;
	}
	while (cmd && cmd->stat == 1)
	{
		cmd = cmd->prev;
		ft_delete_command(ln, 0);
	}
}
