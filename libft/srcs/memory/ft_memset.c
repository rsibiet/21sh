/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:34:02 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:08:55 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	     The memset() function writes len bytes of value c (converted to an
**	     unsigned char) to the string b.
*/

#include "libz.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ret;

	ret = b;
	while (len--)
		*ret++ = (unsigned char)c;
	return (b);
}
