/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:54:29 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:13:26 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Append a copy of the null-terminated string s2 to the end of
**	the null-terminated string s1, then add a terminating `\0'.
**	The string s1 must have sufficient space to hold the result.
**	Append no more than n characters, and add a terminating \0
*/

#include "libz.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	int		d_len;

	i = 0;
	d_len = ft_strlen(dest);
	while (src[i])
	{
		if (i == (int)n)
			break ;
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (dest);
}
