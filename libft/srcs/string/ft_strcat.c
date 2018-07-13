/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:54:23 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:10:49 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Append a copy of the null-terminated string s2 to the end of
**	the null-terminated string s1, then add a terminating `\0'.
**	The string s1 must have sufficient space to hold the result.
*/

#include "libz.h"

char	*ft_strcat(char *dest, const char *src)
{
	ft_strcpy((dest + ft_strlen(dest)), src);
	return (dest);
}
