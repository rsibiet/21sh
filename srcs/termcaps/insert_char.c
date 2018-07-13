/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:18:24 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/01 17:07:45 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include <curses.h>
#include <term.h>
#include "ft_sh.h"

static t_cmd		*insert_in_quote3(t_cmd *cmd, t_cmd *head,
				t_link_cmd *ln)
{
	int	i;

	i = ln->pos;
	if (i > 0)
	{
		cmd = head;
		while (cmd && i > 0)
		{
			i--;
			cmd = cmd->next;
		}
	}
	else if (cmd && cmd->val == '\n')
		cmd = cmd->next;
	return (cmd);
}

void				insert_in_quote(t_cmd *cmd, int tp, int i, t_link_cmd *ln)
{
	tp = get_len_curpr(ln->pos, ln);
	while (i++ < tp)
		tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
	while (cmd->prev && cmd->val != '\n')
		cmd = cmd->prev;
	cmd = insert_in_quote3(cmd, ln->head, ln);
	while (cmd)
	{
		ft_putchar_int(cmd->val);
		cmd = cmd->next;
	}
}

static void			insert_char2(int i, t_link_cmd *ln)
{
	i = ln->len;
	while (i-- > ln->curse)
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
}

void				insert_char(t_cmd *cmd, t_link_cmd *ln, char c, int i)
{
	t_cmd	*new;

	while (i++ < ln->curse)
		cmd = cmd->next;
	new = ft_cmdnew();
	new->val = c;
	if (cmd->prev != NULL)
		cmd->prev->next = new;
	new->prev = cmd->prev;
	cmd->prev = new;
	new->next = cmd;
	if (new->next == NULL)
		ln->tail = new;
	if (new->prev == NULL)
		ln->head = new;
	ln->len++;
	i = ln->curse + 1;
	tputs(tgetstr("vi", NULL), 1, ft_putchar_int);
	home_end_key(ln, 0, ln->head, 0);
	tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	ln->curse = i;
	insert_in_quote(ln->tail, 0, 0, ln);
	insert_char2(0, ln);
}
