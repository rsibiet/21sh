/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:48:49 by mressier          #+#    #+#             */
/*   Updated: 2016/04/27 19:48:51 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char		*cut(char **cmd, int start, int end, int *wrd)
{
	char	*tmp;

	tmp = ft_cut_str(*cmd, start, end);
	ft_strdel(cmd);
	*wrd = -1;
	return (tmp);
}

static int		is_a_dot_slash(char *cmd, int i)
{
	if ((i && cmd[i - 1] != '.' && cmd[i] == '.'
			&& (cmd[i + 1] == '/' || !cmd[i + 1]))
			|| (i == 0 && cmd[i] == '.' && cmd[i + 1] == '/'))
		return (1);
	return (0);
}

static int		is_a_dot_dot_slash(char *cmd, int i)
{
	if (cmd[i] == '.' && cmd[i + 1] == '.'
			&& ((cmd[i + 2] && cmd[i + 2] == '/') || cmd[i + 2] == '\0'))
		return (1);
	return (0);
}

static int		parse_char(char **cmd, int i, int *wrd)
{
	if ((ft_isalpha((*cmd)[i]) && i == 0)
			|| (i > 0 && ft_isalpha((*cmd)[i]) && (*cmd)[i - 1] == '/'))
		*wrd = i;
	else
	{
		if ((*cmd)[i] == '/' && (*cmd)[i + 1] && (*cmd)[i + 1] == '/')
			(*cmd) = cut(cmd, i, i, wrd);
		if (is_a_dot_slash((*cmd), i))
			(*cmd) = cut(cmd, i, i + 1, wrd);
		else if (is_a_dot_dot_slash((*cmd), i) && *wrd != -1)
			(*cmd) = cut(cmd, *wrd, i + 2, wrd);
		else if (is_a_dot_dot_slash((*cmd), i)
				&& (i - 1 == 0 && (*cmd)[i - 1] == '/'))
			(*cmd) = cut(cmd, i, i + 2, wrd);
		else
			return (1);
		return (0);
	}
	return (1);
}

char			*cut_dir(char *cmd)
{
	char	*new;
	int		i;
	int		wrd;

	i = 0;
	wrd = -1;
	new = ft_strdup(cmd);
	while (new[i])
	{
		if (parse_char(&new, i, &wrd))
			i++;
		else
			i = 0;
	}
	return (new);
}
