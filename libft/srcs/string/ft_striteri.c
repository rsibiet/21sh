/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:43:39 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:12:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Apply a ft on each character of the string
*/

#include "libz.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (*s)
			(*f)(i++, s++);
	}
}
