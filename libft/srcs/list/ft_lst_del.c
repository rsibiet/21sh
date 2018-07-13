/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 19:31:14 by mressier          #+#    #+#             */
/*   Updated: 2016/03/03 19:31:15 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void				ft_lst_del_one(t_lst **list, void (*del)(void **))
{
	if (!list || !*list)
		return ;
	del(&(*list)->data);
	ft_memdel((void **)list);
}

void				ft_lst_del(t_lst **list, void (*del)(void **))
{
	t_lst	*tmp;

	if (!list || !*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		ft_lst_del_one(list, del);
		*list = tmp;
	}
}
