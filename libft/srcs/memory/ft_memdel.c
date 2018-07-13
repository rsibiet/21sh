/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:12:40 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:08:35 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Free the memory and set it at NULL
*/

#include "libz.h"

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
