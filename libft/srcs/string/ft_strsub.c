/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:58:22 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:15:26 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return a str of the piece of s (since s[start] with a lenght of len)
*/

#include "libz.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new_s;

	if (!s)
		return (NULL);
	new_s = ft_strndup(&(s[start]), len);
	return (new_s);
}
