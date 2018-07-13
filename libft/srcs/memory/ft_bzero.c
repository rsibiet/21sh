/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:43:17 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:03:55 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION
**     The bzero() function writes n zeroed bytes to the string s.  If n is
**     zero, bzero() does nothing.
*/

#include "libz.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
