/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_21sh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:33:52 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/02 18:21:22 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "libz.h"
#include "ft_sh.h"

static int		read_input_3(t_link_cmd *ln, char c[4], int i,
					t_link_hist *lh)
{
	if (c[0] == 27 && c[1] == 91 && (c[2] == 70 || c[2] == 72))
		home_end_key(ln, c[2], ln->head, 0);
	else if (c[0] == 12 && c[1] == 0 && c[2] == 0)
		clear_screen_sh(ln, ln->head, 0);
	else if (c[0] != 9 && c[1] != 0 && c[2] != 0 && c[0] != 27
		&& c[1] != 91 && c[2] != 51 && c[2] != 54 && c[2] != 53)
	{
		while (i < 4 && c[i])
		{
			if (c[i] == 10)
			{
				lh->pos_n = i;
				while (i++ < 4)
					lh->c[i - 1] = c[i - 1];
				return (1);
			}
			stick_ext(ln->head, ln, c[i++], 0);
		}
	}
	return (0);
}

static int		read_input_2(t_link_cmd *ln, t_link_hist *lh,
					char c[4])
{
	if (c[0] == 18 && c[1] == 0 && c[2] == 0)
	{
		clear_cmd(ln, NULL);
		ft_putstr_intfd("\nbck-i-search: ");
		lh->sig_int = 0;
		ctrl_r_21sh(ln, 0, lh);
	}
	else if (c[0] == 57 && (c[1] == 65 || c[1] == 66))
		ctrl_up_down(0, c[1], ln, 0);
	else if (ft_isprint((int)c[0]) == 1 && c[1] == 0)
		insert_char(ln->head, ln, c[0], 0);
	else if (c[0] == 57 && c[2] == 0 && (c[1] == 67 || c[1] == 68))
		move_by_word(ln, c[1], 0, ln->head);
	else if (c[0] == '\177' && c[1] == 0)
		ft_delete_command(ln, 0);
	else if (c[0] == -61 || (c[0] == -30 && lh->copy != NULL))
		copy_cut_stick(c, ln, 1, lh);
	else if (c[0] == 10 && (c[1] == 0 || c[1] == -1))
	{
		if (quotes_21sh(ln, ln->head) == 0)
			return (1);
	}
	else if (read_input_3(ln, c, 0, lh) == 1)
		return (1);
	return (0);
}

static void		read_input(t_link_cmd *ln, t_hist *hist, t_link_hist *lh)
{
	char		c[4];

	ft_bzero(c, sizeof(char) * 4);
	read(0, c, 4);
	if (lh->sig_cl == 1)
		lh = ft_save_lh(NULL, 1);
	else if (c[0] == 4 && c[1] == 0 && c[2] == 0)
	{
		if (ctrl_d(ln, lh) == 1)
			return ;
	}
	else if (c[0] == 9 && c[1] == 0 && c[2] == 0 && ln->head->val != 0)
	{
		if (autocompletion(ln, ln->head, lh) == 1)
			return ;
	}
	else if (c[0] == '\033' && c[1] == '[' && c[2] >= 65 && c[2] <= 68)
		move_cursor(ln, c, &hist, lh);
	else if (read_input_2(ln, lh, c) == 1)
		return ;
	ft_save_cmd(ln, 0);
	read_input(ln, hist, lh);
}

char			*termcaps_21sh(t_link_hist *lh)
{
	t_link_cmd		link;
	t_cmd			*cmd;
	char			*s;

	cmd = ft_cmdnew();
	link = init_cmd(cmd);
	ft_save_lh(lh, 0);
	lh->cur = lh->head;
	insert_cmd_tmp(lh, &link, 0);
	if (init_termcaps() == -1)
		return (NULL);
	if (lh->c[lh->pos_n] == '\n')
	{
		while (lh->pos_n++ < 4)
			insert_char(link.head, &link, lh->c[lh->pos_n], 0);
		ft_bzero(lh->c, sizeof(char) * 4);
	}
	read_input(&link, lh->head, lh);
	s = put_command(&link, 0, NULL, link.head);
	if (s[0] != '\0' && lh->tp == NULL && lh->sig_cl != 2)
		update_historique(lh->head->next, lh, s, NULL);
	reset_termcaps();
	return (s);
}
