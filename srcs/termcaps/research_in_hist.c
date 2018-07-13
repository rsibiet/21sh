/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_in_hist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 14:15:25 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/02 18:20:34 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "ft_sh.h"
#include <curses.h>
#include <term.h>
#include <stdlib.h>

static t_hist	*ctrl_r_3(t_hist *hist, t_link_cmd *ln, int i, int j)
{
	while (hist)
	{
		if (hist->s != NULL)
		{
			i = 0;
			while (hist->s[i] != '\0')
			{
				if (ln->tmp != NULL && hist->s[i++] == ln->tmp[0])
				{
					j = 0;
					while (hist->s[i - 1 + j] == ln->tmp[j] &&
							hist->s[i - 1 + j] != '\0' && ln->tmp[j] != '\0')
						j++;
				}
				if (ln->tmp[j] == '\0')
					return (hist);
			}
		}
		hist = hist->next;
	}
	return (NULL);
}

static void		ctrl_r_4(int j, t_link_cmd *ln, t_hist *hist)
{
	ft_putstr_intfd(ln->tmp);
	if (hist != NULL)
	{
		ft_putstr_intfd(" --> ");
		ft_putstr_intfd(hist->s);
		ln->search = hist->s;
		j = 5 + ft_strlen(hist->s);
	}
	while (j-- > 0)
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
}

static void		ctrl_r_2(int i, char c, t_link_cmd *ln, t_hist *hist)
{
	char	*s;
	int		j;

	j = 0;
	s = (char *)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	s[i - 1] = c;
	while (ln->tmp && ln->tmp[j++] != '\0')
		s[j - 1] = ln->tmp[j - 1];
	if (ln->tmp != NULL)
		ft_strdel(&ln->tmp);
	ln->tmp = s;
	if ((hist = ctrl_r_3(ft_save_lh(NULL, 1)->head, ln, 0, 0)) == NULL)
	{
		tputs(tgetstr("dl", NULL), 1, ft_putchar_int);
		tputs(tgetstr("up", NULL), 1, ft_putchar_int);
		if (ln->search != NULL)
			ln->search = NULL;
		ft_putstr_intfd("\nfailing bck-i-search: ");
	}
	ctrl_r_4(0, ln, hist);
}

static void		display_searchbar(int *i, int tp, t_link_cmd *ln)
{
	if (*i > 0)
	{
		tputs(tgetstr("dl", NULL), 1, ft_putchar_int);
		tputs(tgetstr("up", NULL), 1, ft_putchar_int);
	}
	if (*i > 0)
		ft_putstr_intfd("\nbck-i-search: ");
	else
		*i = 0;
	if (tp == -1)
	{
		if (ln->search != NULL)
			ft_strdel(&ln->search);
		*i = -1;
		if (ln->tmp != NULL)
			ft_strdel(&ln->tmp);
	}
	else
	{
		if (i == 0 && ln->tmp != NULL)
			ft_strdel(&ln->tmp);
	}
}

void			ctrl_r_21sh(t_link_cmd *ln, int i, t_link_hist *lh)
{
	char	c[3];

	read(0, c, 3);
	if (lh->sig_int == 1)
	{
		insert_char(ln->head, ln, c[0], 0);
		return ;
	}
	if (c[0] == '\177' && c[1] == 0)
		display_searchbar(&i, -1, ln);
	else if (ft_isprint((int)c[0]) == 1 && c[1] == 0 && i < 20)
	{
		display_searchbar(&i, 1, ln);
		while (i == 0 && ln->curse > 0)
			ft_delete_command(ln, 0);
		i++;
		ctrl_r_2(i, c[0], ln, NULL);
	}
	else if (ctrl_r_21sh2(ln, 0, c) == 1)
		return ;
	ctrl_r_21sh(ln, i, lh);
}
