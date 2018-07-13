/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:58:31 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:16:26 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return a copy of s without blank at start and end of the str
*/

#include "libz.h"

static char		*baby_trim(char *new, int *n, int *i, char *tmp_s)
{
	if (new && new[0] != '\0')
		new = ft_strfjoin(&new, " ");
	new = ft_strnfjoin(&new, &tmp_s[*n], *i - *n);
	while (tmp_s[*i] && ft_isspace(tmp_s[*i]))
		(*i)++;
	*n = *i;
	return (new);
}

char			*ft_strintrim(const char *s)
{
	char	*tmp_s;
	char	*new;
	int		i;
	int		n;

	tmp_s = ft_strtrim(s);
	i = 0;
	n = 0;
	new = ft_strnew(0);
	while (tmp_s[i])
	{
		if (ft_isspace(tmp_s[i]))
			new = baby_trim(new, &n, &i, tmp_s);
		else
			i++;
	}
	if (n != i)
	{
		if (new && new[0] != '\0')
			new = ft_strfjoin(&new, " ");
		new = ft_strnfjoin(&new, &tmp_s[n], i - n);
	}
	ft_strdel(&tmp_s);
	return (new);
}

char			*ft_strtrim(const char *s)
{
	size_t				i;
	size_t				start;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && ft_isspace(s[i]))
		i++;
	if ((start = i) == ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i--;
	return (ft_strsub(s, start, i - start + 1));
}
