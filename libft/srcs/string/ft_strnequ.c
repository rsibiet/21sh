/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:55:02 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:13:55 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return 1 or 0 if two strings are equals
*/

#include "libz.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!n || (!s1 && !s2))
		return (1);
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && *s1 && *s2 && --n)
	{
		s1++;
		s2++;
	}
	return ((*s1 == *s2));
}
