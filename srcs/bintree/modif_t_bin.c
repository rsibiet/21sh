/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_t_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:31:59 by mressier          #+#    #+#             */
/*   Updated: 2016/05/11 19:32:00 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_bin				*modif_t_bin(t_bin *branch, int ope, char *str)
{
	if (!branch)
		return (branch);
	branch->ope = ope;
	if (branch->cmd)
		ft_strdel(&branch->cmd);
	branch->cmd = str;
	return (branch);
}
