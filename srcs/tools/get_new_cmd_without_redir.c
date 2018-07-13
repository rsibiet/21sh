/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_cmd_without_redir.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 16:35:29 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 14:57:54 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int			find_in_str_with_quote(char *str, int start, int c)
{
	int		i;
	int		count;

	i = start;
	count = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
		{
			if (count == 0)
				count = str[i];
			else if (count == str[i])
				count = 0;
		}
		if (count == 0)
		{
			if (str[i] == c
					|| (c == ' ' && (is_separator(str[i + 1])
					|| str[i + 1] == c)))
				return (i);
		}
		i++;
	}
	return (i);
}

int					get_end_cmd(char *str, int end)
{
	int				n;

	n = ' ';
	while (str[end] && ft_isspace(str[end]))
		end++;
	if (is_quote(str[end]))
		n = str[end];
	end = find_in_str_with_quote(str, end, n);
	return (end);
}

char				*get_new_cmd_without_redir(char *str, int pos, int c)
{
	char			*new;
	int				start;
	int				end;

	if (c == REDIR_RIGHT_ET || c == REDIR_LEFT_ET)
		end = pos + 1;
	else
		end = pos;
	if (c == DB_REDIR_RIGHT || c == DB_REDIR_LEFT)
		start = pos - 1;
	else
		start = pos;
	end++;
	end = get_end_cmd(str, end);
	new = ft_cut_str(str, start, end);
	ft_str_replace_str(&new, sh_strintrim(new));
	return (new);
}
