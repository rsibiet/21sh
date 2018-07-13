/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_once.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:47:01 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 12:47:03 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

static int	count_word(const char *s, int c, int nb)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (nb < 0)
		return (1);
	while (s[i] && nb >= 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			nb--;
			n++;
		}
		i++;
	}
	return (n);
}

static char	**get_split(int *i_s, const char *s, int c, int n)
{
	char	**tab;
	char	*tmp;
	int		len;
	int		i_tab;
	int		i;

	i = 0;
	i_tab = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * (count_word(s, c, n) + 1));
	while (s[i] && n > 0)
	{
		if (((i && s[i - 1] == c) || i == 0) && s[i] != c)
		{
			tmp = (char *)&s[i];
			len = ft_strclen(tmp, c);
			(len == -1) ? len = ft_strlen(tmp) : 0;
			tab[i_tab++] = ft_strsub(s, i, len);
			i += len;
			n--;
		}
		else
			i++;
	}
	*i_s = i;
	return (tab);
}

char		**ft_strsplit_ntime(const char *s, char c, int n)
{
	int		i_s;
	char	**tab;

	i_s = 0;
	tab = get_split(&i_s, s, c, n);
	if (s[i_s])
	{
		s[i_s] == c ? i_s++ : i_s;
		tab[ft_str_array_len(tab)] = ft_strsub(s, i_s, ft_strlen(&(s[i_s])));
	}
	tab[ft_str_array_len(tab)] = NULL;
	return (tab);
}
