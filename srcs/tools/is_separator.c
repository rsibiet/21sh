/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:45:15 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 10:05:36 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					is_separator(char c)
{
	if (c == SEMI_COLONS
			|| c == C_PIPE
			|| c == REDIR_RIGHT
			|| c == REDIR_LEFT)
		return (1);
	return (0);
}

int					get_separator_char(char *str, int i)
{
	if (str[i] == REDIR_RIGHT || str[i] == REDIR_LEFT)
	{
		if (str[i + 1] == '&')
			return ((str[i] == REDIR_RIGHT) ? REDIR_RIGHT_ET : REDIR_LEFT_ET);
		if ((i - 1 >= 0 && str[i - 1] == str[i]))
			return ((str[i] == REDIR_RIGHT) ? DB_REDIR_RIGHT : DB_REDIR_LEFT);
		else if (str[i + 1] == str[i])
			return (0);
		return (str[i]);
	}
	if (str[i] == C_PIPE)
	{
		if (!((i - 1 >= 0 && str[i - 1] == C_PIPE) || str[i + 1] == C_PIPE))
			return (C_PIPE);
	}
	if (str[i] == SEMI_COLONS)
		return (str[i]);
	return (0);
}
