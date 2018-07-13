/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 20:04:34 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:08:08 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The memchr() function locates the first occurrence of c (converted to an
**	unsigned char) in string s.
**		RETURN VALUES
**	The memchr() function returns a pointer to the byte located, or NULL if
**	no such byte exists within n bytes.
*/

#include "libz.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cp_s;

	cp_s = (unsigned char *)s;
	while (n--)
	{
		if (*cp_s == (unsigned char)c)
			return (cp_s);
		cp_s++;
	}
	return (NULL);
}
