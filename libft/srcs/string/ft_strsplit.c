/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:25:50 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:14:36 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return an array of string create by the split of the s with the char c
** s = "hello les moches" with the char ' ' make "hello" "les" "moches"
*/

#include "libz.h"

static int	count_word(const char *s, int c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i_tab;
	int		i_s;
	int		len;
	char	**tab;
	char	*tmp;

	i_tab = 0;
	i_s = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * (count_word(s, c) + 1));
	while (s[i_s])
	{
		if (((i_s && s[i_s - 1] == c) || i_s == 0) && s[i_s] != c)
		{
			tmp = (char *)&s[i_s];
			len = ft_strclen(tmp, c);
			(len == -1) ? len = ft_strlen(tmp) : 0;
			tab[i_tab] = ft_strsub(s, i_s, len);
			i_tab++;
			i_s += len;
		}
		else
			i_s++;
	}
	tab[i_tab] = NULL;
	return (tab);
}

char		**ft_strsplit_index(const char *s, int index)
{
	char		**tab;

	tab = (char **)ft_memalloc(sizeof(char *) * 3);
	tab[0] = ft_strsub(s, 0, index);
	tab[1] = ft_strsub(s, index, ft_strlen(s) - index);
	tab[2] = NULL;
	return (tab);
}
