/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:57:08 by mressier          #+#    #+#             */
/*   Updated: 2016/03/02 13:57:09 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

/*
**	Add an element just before the element 'list'
*/

t_lst	*ft_lst_add(t_lst *to_add, t_lst *list)
{
	if (list == NULL)
		return (to_add);
	to_add->next = list;
	return (to_add);
}
