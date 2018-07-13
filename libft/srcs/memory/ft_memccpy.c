/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:55:24 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:08:01 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Copy at most n bytes from dst to src (man memccpy)
*/

#include "libz.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*cpy_dest;
	unsigned char		*cpy_src;

	cpy_dest = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	while (n--)
	{
		if (*cpy_src == (unsigned char)c)
		{
			*cpy_dest++ = *cpy_src++;
			return (cpy_dest);
		}
		*cpy_dest++ = *cpy_src++;
	}
	return (NULL);
}
