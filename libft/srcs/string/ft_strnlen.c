/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:26:08 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:14:16 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	function attempts to compute the length of s, but never scans beyond the
**	first maxlen bytes of s.
*/

#include "libz.h"

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t		n;

	n = ft_strlen(s);
	if (n > maxlen)
		return (maxlen);
	else
		return (n);
}
