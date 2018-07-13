/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:32:14 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:11:04 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return the lenght between s and a char c in the string.
**	If c isn't in the string, it return -1
*/

#include "libz.h"

int		ft_strclen(const char *s, int c)
{
	char	*cur;

	cur = ft_strchr(s, c);
	if (cur == NULL)
		return (-1);
	else
		return (cur - s);
}
