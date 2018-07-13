/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:10:09 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:14:43 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Catch the first occurence of the str little in the big, and return a pointer
**	on it, or NULL if it's not find on it
*/

#include "libz.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	len_little;

	len_little = ft_strlen(little);
	if (len_little > ft_strlen(big))
		return (NULL);
	while (ft_strlen(big) >= len_little)
	{
		if (ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
