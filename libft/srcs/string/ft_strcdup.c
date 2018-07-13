/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:03:37 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 19:03:38 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

/*
**	Create a new string with str until the char c or until the end.
*/

char	*ft_strcdup(const char *str, int c)
{
	char	*new_str;
	int		len;

	len = ft_strclen(str, c);
	if (len == -1)
		len = ft_strlen(str);
	new_str = ft_strsub(str, 0, len);
	return (new_str);
}
