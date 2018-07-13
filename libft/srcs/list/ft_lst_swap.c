/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:03:22 by mressier          #+#    #+#             */
/*   Updated: 2016/03/02 14:03:23 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_lst	*ft_lst_swap(t_lst *to_swap1, t_lst *to_swap2)
{
	void		*tmp;

	tmp = to_swap1->data;
	to_swap1->data = to_swap2->data;
	to_swap2->data = tmp;
	return (to_swap1);
}
