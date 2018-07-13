/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_new_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:46:23 by mressier          #+#    #+#             */
/*   Updated: 2016/03/02 12:46:24 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_lst	*ft_lst_new(void *new_file)
{
	t_lst	*new_lst;

	new_lst = (t_lst *)ft_memalloc(sizeof(t_lst));
	new_lst->data = new_file;
	new_lst->next = NULL;
	return (new_lst);
}
