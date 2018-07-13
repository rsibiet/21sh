/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:06:45 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:08:16 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The memcmp() function compares byte string s1 against byte string s2.
**	Both strings are assumed to be n bytes long.
*/

#include "libz.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *cp_s1;
	unsigned char *cp_s2;

	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*cp_s1 != *cp_s2)
			return (*cp_s1 - *cp_s2);
		cp_s1++;
		cp_s2++;
	}
	return (0);
}
