/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:54:47 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:12:12 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return 1 or 0 if the str are equal or not
*/

#include "libz.h"

int			ft_strequ_end(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	if (j > i)
		return (0);
	while (i >= 0 && j >= 0)
	{
		if (s1[i] != s2[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int			ft_strequ(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	return ((ft_strcmp(s1, s2)) == 0);
}
