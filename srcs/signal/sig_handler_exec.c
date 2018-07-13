/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:26:13 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 14:26:14 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "termcaps.h"

void		ft_init_signal_handler_exec(void)
{
	ft_init_signal(SIGINT, sig_handler_exec);
	ft_init_signal(SIGSEGV, sig_handler_exec);
	ft_init_signal(SIGBUS, sig_handler_exec);
	ft_init_signal(SIGABRT, sig_handler_exec);
	ft_init_signal(SIGTSTP, SIG_IGN);
	ft_init_signal(SIGQUIT, SIG_IGN);
	ft_init_signal(SIGTERM, SIG_IGN);
}

void		ft_reset_signal_handler_exec(void)
{
	ft_reset_signal(SIGINT);
	ft_reset_signal(SIGSEGV);
	ft_reset_signal(SIGBUS);
	ft_reset_signal(SIGABRT);
	ft_reset_signal(SIGTSTP);
}

void		sig_handler_exec(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_int('\n');
		return ;
	}
	if (sig == SIGABRT)
		ft_putstr_color(C_G_RED, "Warning : Abort.\n");
	else if (sig == SIGBUS)
		ft_putstr_color(C_G_RED, "Warning : Bus error.\n");
	else if (sig == SIGSEGV)
		ft_putstr_color(C_G_RED, "Warning : Segmentation fault.\n");
	exit(1);
}
