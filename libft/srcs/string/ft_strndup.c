/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:20:11 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:13:48 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	It copies at most n characters from the string s1
**	always NUL terminating the copied string.
*/

#include "libz.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*new_s;

	if ((int)n < 0)
		n = ft_strlen(s);
	new_s = ft_strnew(n);
	new_s = ft_strncpy(new_s, s, n);
	return (new_s);
}
