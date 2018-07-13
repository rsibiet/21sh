/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_get_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:51:36 by mressier          #+#    #+#             */
/*   Updated: 2016/03/02 13:51:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_lst		*ft_lst_get_last(t_lst *list)
{
	t_lst	*cur;

	cur = list;
	if (list == NULL)
		return (NULL);
	while (cur->next)
		cur = cur->next;
	return (cur);
}
