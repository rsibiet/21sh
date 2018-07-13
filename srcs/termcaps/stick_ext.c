/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stick_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:43:07 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/19 18:52:25 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "ft_sh.h"

void				stick_ext(t_cmd *cmd, t_link_cmd *ln, char c, int i)
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
	ln->curse++;
	ft_putchar_int(c);
}
