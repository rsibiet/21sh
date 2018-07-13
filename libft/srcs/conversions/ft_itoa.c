/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:02:52 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:17:29 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Convert an int into a str
*/

#include "libz.h"

char		*ft_itoa(int n)
{
	char	*s;
	int		size;

	if (n == (int)-2147483648u)
		return (ft_strdup("-2147483648"));
	size = ft_signed_len(n, 10);
	if ((s = ft_strnew(size)) == NULL)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		s[--size] = n % 10 + 48;
		n /= 10;
	}
	s[--size] = n + 48;
	return (s);
}
