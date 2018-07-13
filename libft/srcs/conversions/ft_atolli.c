/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:43:16 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:17:25 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Convert a str into an int
*/

#include "libz.h"

long long int			ft_atolli(const char *nptr)
{
	unsigned long long int	n;

	n = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if ((*nptr == '-' && ft_isdigit(*(nptr + 1))) ||
		(*nptr == '+' && ft_isdigit(*(nptr + 1))))
		return ((*nptr == '-') ? -(ft_atolli(++nptr)) : ft_atolli(++nptr));
	while (ft_isdigit(*nptr))
		n = n * 10 + *nptr++ - 48;
	return (n);
}
