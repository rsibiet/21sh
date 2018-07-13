/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:21:50 by rsibiet           #+#    #+#             */
/*   Updated: 2016/04/25 14:20:10 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

t_link_hist				*ft_save_lh(t_link_hist *lh, int i)
{
	static t_link_hist	*tp = NULL;

	if (i == 0)
		tp = lh;
	return (tp);
}

t_link_cmd				*ft_save_cmd(t_link_cmd *cmd, int i)
{
	static t_link_cmd	*save_cmd = NULL;

	if (i == 0)
		save_cmd = cmd;
	return (save_cmd);
}
