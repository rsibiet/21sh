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

static void	sig_handler_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		reset_termcaps();
		exit(0);
	}
}

void		ft_init_sig_handler_heredoc(void)
{
	ft_init_signal(SIGINT, sig_handler_heredoc);
	ft_init_signal(SIGTSTP, SIG_IGN);
	ft_init_signal(SIGQUIT, SIG_IGN);
	ft_init_signal(SIGTERM, SIG_IGN);
}

void		ft_reset_sig_handler_heredoc(void)
{
	ft_reset_signal(SIGINT);
	ft_reset_signal(SIGSEGV);
	ft_reset_signal(SIGBUS);
	ft_reset_signal(SIGABRT);
	ft_reset_signal(SIGTSTP);
}
