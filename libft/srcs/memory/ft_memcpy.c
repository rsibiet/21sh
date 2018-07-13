/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:00:18 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:08:28 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   -------------------------------------------------------------------------
**	|		DESCRIPTION                                                       |
**	| The ft_memcpy() function copies n bytes from memory area src to memory  |
**	| area dst.  If dst and src overlap, behavior is undefined.  Applications |
**	| which dst and src might overlap should use memmove(3) instead.          |
**	|                                                                         |
**	|		RETURN VALUES                                                     |
**	| The ft_memcpy() function returns the original value of dst.             |
**	 -------------------------------------------------------------------------
*/

#include "libz.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cp_dst;
	unsigned char	*cp_src;

	cp_dst = (unsigned char *)dst;
	cp_src = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (n--)
		*cp_dst++ = *cp_src++;
	return (dst);
}
