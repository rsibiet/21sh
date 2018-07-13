/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:26:44 by mressier          #+#    #+#             */
/*   Updated: 2016/05/11 11:26:49 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <term.h>
#include <termios.h>
#include "termcaps.h"

static void			reset_error(void)
{
	char	*reset_error;

	reset_error = get_str_error();
	if (reset_error)
		ft_strdel(&reset_error);
}

void				reset_termcaps(void)
{
	struct termios	term;

	tputs(tgetstr("cr", NULL), 1, &ft_putchar_int);
	if (tcgetattr(0, &term) == -1)
	{
		ft_puterror("Cannot access to termios");
		return ;
	}
	term.c_lflag |= (ICANON | ECHO);
	term.c_oflag |= (OPOST);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		ft_puterror("Cannot set termcaps");
}

void				exit_shell(int value, t_core **core)
{
	reset_error();
	reset_termcaps();
	ft_reset_signal_handler_g();
	del_core(core);
	exit(value);
}
