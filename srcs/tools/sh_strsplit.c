/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:51:55 by mressier          #+#    #+#             */
/*   Updated: 2016/05/18 10:51:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int		count_word(const char *s, int c)
{
	int		n;
	int		i;
	int		qt;

	n = 0;
	i = 0;
	qt = 0;
	while (s[i])
	{
		if (is_quote(s[i]))
		{
			if (qt == 0)
			{
				qt = s[i];
				n++;
			}
			else if (qt == s[i])
				qt = 0;
		}
		if (qt == 0 && s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static int		ft_strclen_iter(const char *str, int (*cmp)(int))
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (cmp(str[i]))
			return (i);
		i++;
	}
	return (-1);
}

static int		get_len_part(char *str, int c, int len, int qt_len)
{
	int		i;
	int		count;

	if (qt_len < len && qt_len != -1)
	{
		count = 1;
		i = qt_len + 1;
		while (str[i])
		{
			if (count == 0 && str[i] == c)
				break ;
			else if (count == 0 && is_quote(str[i]))
			{
				count = 1;
				qt_len = i;
			}
			else if (str[i] == str[qt_len])
				count = 0;
			i++;
		}
		len = i;
	}
	return (len);
}

static char		*get_part(const char *s, int *i_s, int c)
{
	int		len;
	int		qt_len;
	char	*tmp;
	char	*new;

	tmp = (char *)&s[*i_s];
	len = ft_strclen(tmp, c);
	if (len == -1)
		len = ft_strlen(tmp);
	qt_len = ft_strclen_iter(tmp, is_quote);
	len = get_len_part(tmp, c, len, qt_len);
	new = ft_strsub(s, *i_s, len);
	(*i_s) = *i_s + len;
	return (new);
}

char			**sh_strsplit(const char *s, char c)
{
	int		i_tab;
	int		i_s;
	char	**tab;

	i_s = 0;
	i_tab = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * (count_word(s, c) + 1));
	while (s[i_s])
	{
		if (((i_s && ((s[i_s - 1] == c) || is_quote(s[i_s - 1]))) || i_s == 0)
				&& s[i_s] != c)
			tab[i_tab++] = get_part(s, &i_s, c);
		else
			i_s++;
	}
	tab[i_tab] = NULL;
	return (tab);
}
