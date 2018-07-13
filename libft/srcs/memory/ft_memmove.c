/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:34:19 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:08:49 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 		DESCRIPTION
**	The memmove() function copies len bytes from string src to string dst.
**	The two strings may overlap; the copy is always done in a non-destructive
**	manner.
**		RETURN VALUES
**	The memmove() function returns the original value of dst.
*/

#include "libz.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;

	cpy_dest = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	if (cpy_dest <= cpy_src)
		cpy_dest = ft_memcpy(cpy_dest, cpy_src, len);
	else
	{
		cpy_dest += len - 1;
		cpy_src += len - 1;
		while (len--)
			*cpy_dest-- = *cpy_src--;
	}
	return ((void *)dst);
}
