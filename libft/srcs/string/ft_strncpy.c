/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:45:24 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 12:21:38 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Copy at most len characters. If src is less than len char long,
**	dest is filled with \0 characters. Otherwise, dst is not terminated
*/

#include "libz.h"

char	*ft_strncpy(const char *dest, const char *src, size_t len)
{
	int		i;
	char	*cp_dst;

	i = 0;
	cp_dst = (char *)dest;
	while (src[i])
	{
		if (i == (int)len)
			break ;
		cp_dst[i] = src[i];
		i++;
	}
	while (i < (int)len)
		cp_dst[i++] = '\0';
	return (cp_dst);
}
