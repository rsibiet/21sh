/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_once.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 13:17:53 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 13:17:55 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

#define ONE_STR 2
#define TWO_STR 3

char	**ft_strsplit_once(const char *str, char c)
{
	char	**new;
	int		len;

	len = ft_strclen(str, c);
	if (len == -1)
	{
		len = ft_strlen(str);
		new = (char **)ft_memalloc(sizeof(char *) * ONE_STR);
	}
	else
		new = (char **)ft_memalloc(sizeof(char *) * TWO_STR);
	new[0] = ft_strsub(str, 0, len);
	if (str[len])
	{
		new[1] = ft_strsub(str, len + 1, ft_strlen(str) - (len + 1));
		new[2] = NULL;
	}
	else
		new[1] = NULL;
	return (new);
}
