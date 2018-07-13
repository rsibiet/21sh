/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_branch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:30:25 by mressier          #+#    #+#             */
/*   Updated: 2016/05/17 11:04:00 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_bin				*modif_branch(t_bin *branch, int c)
{
	if (c == REDIR_LEFT || c == REDIR_RIGHT
			|| c == DB_REDIR_RIGHT || c == DB_REDIR_LEFT
			|| c == REDIR_RIGHT_ET || c == REDIR_LEFT_ET)
		branch = redir_left_right_modif(branch, c);
	else if (c == C_PIPE)
		branch = pipe_modif(branch);
	else if (c == SEMI_COLONS)
		branch = semi_colons_modif(branch);
	return (branch);
}
