/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:06:54 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:07:55 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocate and return a memory set with 0.
*/

#include "libz.h"

void		*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = ft_malloc(size);
	if (mem)
		ft_memset(mem, '\0', size);
	return (mem);
}
