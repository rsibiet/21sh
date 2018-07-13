/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:08:29 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:14:24 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Find the first occurence of little in the n first char of big
**	Return a pointer on it, or NULL if not found
*/

#include "libz.h"

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	while (n >= ft_strlen(little) && *big)
	{
		if (ft_strncmp(big, little, ft_strlen(little)) == 0)
			return ((char *)big);
		big++;
		n--;
	}
	return (NULL);
}
