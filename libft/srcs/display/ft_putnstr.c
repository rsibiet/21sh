/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:19:06 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:20:01 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Put at most n character
*/

#include "libz.h"

void	ft_putnstr(const char *s, size_t n)
{
	if (n < ft_strlen(s))
		write(1, s, n);
	else
		write(1, s, ft_strlen(s));
}
