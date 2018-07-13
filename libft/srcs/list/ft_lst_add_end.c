/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_add_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:55:26 by mressier          #+#    #+#             */
/*   Updated: 2016/03/02 13:55:27 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_lst	*ft_lst_add_end(t_lst *new_lst, t_lst *list)
{
	t_lst	*end;

	if (list == NULL)
		return (new_lst);
	end = ft_lst_get_last(list);
	if (end == NULL)
		return (new_lst);
	else
		end->next = new_lst;
	return (list);
}
