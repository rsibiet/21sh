/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_redir_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:04:59 by mressier          #+#    #+#             */
/*   Updated: 2016/05/11 19:05:01 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					is_a_semi_colons(int c)
{
	if (c == SEMI_COLONS)
		return (1);
	return (0);
}

int					is_a_redir_char(int c)
{
	if (c == REDIR_LEFT || c == REDIR_RIGHT
			|| c == DB_REDIR_RIGHT || c == DB_REDIR_LEFT
			|| c == REDIR_LEFT_ET || c == REDIR_RIGHT_ET)
		return (1);
	return (0);
}

int					is_a_pipe_char(int c)
{
	if (c == C_PIPE)
		return (1);
	return (0);
}

int					is_a_redir_et_char(int c)
{
	if (c == REDIR_LEFT_ET || c == REDIR_RIGHT_ET)
		return (1);
	return (0);
}

int					is_a_redir_pipe_char(int c)
{
	if (c == REDIR_LEFT || c == REDIR_RIGHT
			|| c == C_PIPE || c == DB_REDIR_RIGHT
			|| c == DB_REDIR_LEFT || c == REDIR_LEFT_ET
			|| c == REDIR_RIGHT_ET)
		return (1);
	return (0);
}
