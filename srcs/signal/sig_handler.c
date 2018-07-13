/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler_g.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 20:47:10 by mressier          #+#    #+#             */
/*   Updated: 2016/05/23 13:53:40 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "termcaps.h"
#include <sys/ioctl.h>
#include <curses.h>
#include <term.h>

void			ft_init_signal_handler_g(void)
{
	ft_init_signal(SIGINT, sig_handler_g);
	ft_init_signal(SIGQUIT, sig_handler_g);
	ft_init_signal(SIGTERM, sig_handler_g);
	ft_init_signal(SIGABRT, sig_handler_g);
	ft_init_signal(SIGTSTP, sig_handler_g);
	ft_init_signal(SIGWINCH, sig_handler_g);
}

void			ft_reset_signal_handler_g(void)
{
	ft_reset_signal(SIGQUIT);
	ft_reset_signal(SIGTSTP);
	ft_reset_signal(SIGINT);
	ft_reset_signal(SIGTERM);
	ft_reset_signal(SIGABRT);
	ft_reset_signal(SIGTSTP);
	ft_reset_signal(SIGWINCH);
}

static void		screen_size2(t_link_cmd *ln, t_link_hist *lh)
{
	sleep(1);
	if (ln)
		clear_screen_sh(ln, ln->head, 0);
	else
	{
		tputs(tgetstr("cl", NULL), 1, &ft_putchar_int);
		prompt();
	}
	tputs(tgetstr("ve", NULL), 1, &ft_putchar_int);
	lh->sig_cl = 0;
}

static void		screen_size(int c, t_link_cmd *ln, t_link_hist *lh)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	c = ws.ws_col;
	if (ln)
		ln->c = c;
	if (c < 40)
	{
		tputs(tgetstr("cl", NULL), 1, &ft_putchar_int);
		tputs(tgetstr("vi", NULL), 1, &ft_putchar_int);
		ft_putstr_color(C_G_RED, "screen size too small");
		if (lh)
			lh->sig_cl = 1;
	}
	else if (lh && lh->sig_cl == 1)
		screen_size2(ln, lh);
}

void			sig_handler_g(int sig)
{
	t_link_cmd	*cmd_ln;
	t_link_hist	*head_hist;

	cmd_ln = ft_save_cmd(NULL, 1);
	head_hist = ft_save_lh(NULL, 1);
	if (sig == SIGINT)
	{
		if (cmd_ln)
		{
			if (head_hist)
				head_hist->cur = head_hist->head;
			home_end_key(cmd_ln, 70, cmd_ln->head, 0);
			ft_cmd_del(cmd_ln->head);
			*cmd_ln = init_cmd(ft_cmdnew());
			ft_save_cmd(cmd_ln, 0);
		}
		head_hist->sig_int = 1;
		ft_putstr_intfd("\n");
		tputs(tgetstr("cr", NULL), 1, &ft_putchar_int);
		prompt();
	}
	else if (sig == SIGWINCH)
		screen_size(0, cmd_ln, head_hist);
}
