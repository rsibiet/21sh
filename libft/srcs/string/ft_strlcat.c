/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:54:38 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:12:53 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Copy and concatenate strings and care about the total len of the buffer
**	dest. It returns the size of the str that it try to create
*/

#include "libz.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (size <= dlen)
		return (size + slen);
	size = size - dlen - 1;
	dest = dest + dlen;
	while (*src && size--)
		*dest++ = *src++;
	*dest = '\0';
	return (dlen + slen);
}
