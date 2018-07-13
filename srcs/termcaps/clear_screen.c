/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:22:12 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/19 14:39:25 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include <curses.h>
#include <term.h>
#include "ft_sh.h"

void		clear_screen_sh(t_link_cmd *ln, t_cmd *cmd, int i)
{
	tputs(tgetstr("cl", NULL), 1, ft_putchar_int);
	prompt();
	while (cmd)
	{
		ft_putchar_int(cmd->val);
		cmd = cmd->next;
	}
	i = ln->len;
	while (i-- != ln->curse)
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
}
