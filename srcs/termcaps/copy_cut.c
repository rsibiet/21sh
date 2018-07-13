/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 19:00:22 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/13 19:00:24 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "libz.h"
#include <stdlib.h>
#include <sys/ioctl.h>

static void		copy_cmd(t_link_cmd *ln, t_cmd *cmd, int i, t_link_hist *lh)
{
	int		j;

	j = 0;
	if (lh->copy != NULL)
		ft_strdel(&(lh->copy));
	while (cmd)
	{
		if (i++ == ln->curse)
			cmd->stat = 1;
		if (cmd->stat == 1)
			j++;
		cmd = cmd->next;
	}
	lh->copy = ft_strnew(j + 1);
	lh->copy[j] = '\0';
	cmd = ln->head;
	i = 0;
	while (cmd)
	{
		if (cmd->stat == 1)
			lh->copy[i++] = cmd->val;
		cmd = cmd->next;
	}
}

static void		reset_stat(t_cmd *cmd, int *tp, char c)
{
	if (c == -89 && (*tp == 1 || *tp == -1))
		*tp *= -1;
	else if (c == -119 && *tp == 1)
		*tp = -2;
	else if (c == -119 && *tp == -2)
		*tp = 2;
	while (cmd && *tp != 2)
	{
		cmd->stat = 0;
		cmd = cmd->next;
	}
}

static void		stick_copy(t_link_cmd *ln, int i, t_link_hist *lh)
{
	while (lh->copy[i] != '\0')
		insert_char(ln->head, ln, lh->copy[i++], 0);
}

void			copy_cut_stick(char c[3], t_link_cmd *ln, int tp,
					t_link_hist *lh)
{
	int		nb;

	nb = last_backslash_n(ln->tail, ln->len);
	if (tp < 0)
		read(0, c, 3);
	if (c[1] == -89 || (c[1] == -119 && c[2] == -120))
		reset_stat(ln->head, &tp, c[1]);
	else if (tp < 0 && c[0] == '\033' && c[2] == 'D' && ln->curse > nb)
	{
		ln->curse--;
		copy_cmd(ln, ln->head, 0, lh);
		ln->curse++;
		display_copy_part(ln, nb, ln->curse - 1);
	}
	else if (c[0] == -30 && c[1] == -120 && c[2] == -102 && lh->copy != NULL)
		stick_copy(ln, 0, lh);
	if (tp == 2)
	{
		display_cut_part(ln->tail, ln, 0);
		tp = 1;
	}
	if (tp == 1)
		return ;
	copy_cut_stick(c, ln, tp, lh);
}
