/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_add_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:04:12 by mressier          #+#    #+#             */
/*   Updated: 2016/03/02 13:04:14 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_lst	*ft_lst_add_new(void *new_file, t_lst **ls_list)
{
	t_lst *new_lst;

	new_lst = ft_lst_new(new_file);
	if (ls_list == NULL || *ls_list == NULL)
		return (new_lst);
	new_lst->next = *ls_list;
	*ls_list = new_lst;
	return (new_lst);
}
