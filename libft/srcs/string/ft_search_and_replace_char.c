/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:56:20 by mressier          #+#    #+#             */
/*   Updated: 2016/04/27 10:56:22 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char		*ft_search_and_replace_char(char *str, char *to_put, int c)
{
	char	*new;
	int		i;

	new = NULL;
	if (ft_strchr(str, c) == NULL)
		return (ft_strdup(str));
	i = ft_strclen(str, c);
	new = ft_strnew(ft_strlen(str) - 1 + ft_strlen(to_put));
	new = ft_strncat(new, str, i);
	new = ft_strcat(new, to_put);
	new = ft_strcat(new, &str[i + 1]);
	return (new);
}
