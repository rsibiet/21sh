/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:44:09 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:13:09 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Create a new string with the applications of the ft on the old str
*/

#include "libz.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new_s;
	char	*ret;

	if (!s && !f)
		return (NULL);
	if ((new_s = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	ret = new_s;
	while (*s)
		*new_s++ = f(*s++);
	return (ret);
}
