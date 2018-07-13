/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:12:47 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:08:42 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Duplicate a zone of memory
*/

#include "libz.h"

void	*ft_memdup(const void *s, size_t n)
{
	unsigned char	*cp_s;
	unsigned char	*ret;
	int				i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ret = ft_memalloc(n);
	cp_s = (unsigned char *)s;
	while (n--)
	{
		ret[i] = cp_s[i];
		i++;
	}
	return (ret);
}
