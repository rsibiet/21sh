/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:19:38 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:13:02 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The strlen() function computes the length of the string s.
*/

#include "libz.h"

size_t	ft_strlen(const char *s)
{
	int		n;

	n = 0;
	while (*s)
	{
		s++;
		n++;
	}
	return (n);
}
