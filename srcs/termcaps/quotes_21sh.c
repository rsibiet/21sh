/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_21sh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:01:23 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/02 13:15:57 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "libz.h"

static void		compte_quotes4(t_cmd **cmd, t_link_cmd *ln)
{
	if (*cmd && (*cmd)->val == '{')
		ln->quote[5]++;
	if (*cmd && (*cmd)->val == '}')
		ln->quote[5]--;
}

static void		compte_quotes3(t_cmd **cmd, t_link_cmd *ln)
{
	if (*cmd && (*cmd)->val == ')')
		ln->quote[3]--;
	if (*cmd && (*cmd)->val == '[')
		ln->quote[4]++;
	if (*cmd && (*cmd)->val == ']')
		ln->quote[4]--;
	compte_quotes4(cmd, ln);
}

static void		compte_quotes2(t_cmd **cmd, t_link_cmd *ln)
{
	if (*cmd && (*cmd)->val == '`')
	{
		*cmd = (*cmd)->next;
		while (*cmd && (*cmd)->val != '`')
			*cmd = (*cmd)->next;
	}
	if (*cmd == NULL)
		ln->quote[2] = 1;
	else
		ln->quote[2] = 0;
	if (*cmd && (*cmd)->val == '(')
		ln->quote[3]++;
	compte_quotes3(cmd, ln);
}

static void		compte_quotes(t_cmd **cmd, t_link_cmd *ln)
{
	if ((*cmd)->val == 39)
	{
		*cmd = (*cmd)->next;
		while (*cmd && (*cmd)->val != 39)
			*cmd = (*cmd)->next;
	}
	if (*cmd == NULL)
		ln->quote[0] = 1;
	else
		ln->quote[0] = 0;
	if (*cmd && (*cmd)->val == '"')
	{
		*cmd = (*cmd)->next;
		while (*cmd && (*cmd)->val != '"')
			*cmd = (*cmd)->next;
	}
	if (*cmd == NULL)
		ln->quote[1] = 1;
	else
		ln->quote[1] = 0;
	compte_quotes2(cmd, ln);
}

int				quotes_21sh(t_link_cmd *ln, t_cmd *cmd)
{
	ft_bzero(ln->quote, sizeof(ln->quote));
	while (cmd)
	{
		compte_quotes(&cmd, ln);
		if (cmd != NULL)
			cmd = cmd->next;
	}
	quotes_21sh2(ln, ft_save_lh(NULL, 1), NULL);
	if (ln->quote[0] == 1 || ln->quote[1] == 1 || ln->quote[2] == 1)
	{
		add_backslash_n(ln, NULL);
		return (1);
	}
	else if (ln->quote[3] > 0 || ln->quote[5] > 0)
		return (1);
	return (0);
}
