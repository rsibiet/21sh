/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 10:20:37 by mressier          #+#    #+#             */
/*   Updated: 2016/05/02 10:20:38 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function is pretty similar to strsplit, except that it split on all
**	the c char.
**	Example : "toto==truc" on '=' give
**	[0] = toto, [1] = "", [2] = "truc"
*/

#include "libz.h"

static int			count_splits(const char *str, int c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count + 1);
}

char				**ft_explode(const char *str, int c)
{
	char	**tab;
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * (count_splits(str, c) + 1));
	while (str[i])
	{
		if (str[i] == c)
		{
			tab[j] = ft_strsub(str, ret, i - ret);
			j++;
			ret = i + 1;
		}
		i++;
	}
	tab[j++] = ft_strsub(str, ret, i);
	tab[j] = NULL;
	return (tab);
}
