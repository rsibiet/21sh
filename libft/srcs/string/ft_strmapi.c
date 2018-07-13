/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:44:33 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:13:18 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Create a new string with the applications of the ft on the old str
*/

#include "libz.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	char	*ret;
	int		i;

	i = 0;
	if (!s && !f)
		return (NULL);
	if ((new_s = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	ret = new_s;
	while (*s)
		*new_s++ = f(i++, *s++);
	return (ret);
}
