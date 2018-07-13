/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ls_lst_to_start.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:44:12 by mressier          #+#    #+#             */
/*   Updated: 2016/03/02 16:44:14 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void		ft_move_lst_to_start(t_lst *to_move, t_lst **list)
{
	t_lst	*cur;
	t_lst	*tmp;

	cur = *list;
	if (cur == to_move)
		return ;
	while (cur->next != to_move && cur->next)
		cur = cur->next;
	if (cur->next)
	{
		tmp = cur->next->next;
		*list = ft_lst_add(to_move, *list);
		cur->next = tmp;
	}
}
