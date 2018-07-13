/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcfjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:54:02 by mressier          #+#    #+#             */
/*   Updated: 2016/02/01 11:54:05 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char		*ft_strcfjoin(char **s1, const char *s2, char c)
{
	int		len;
	char	*ret;

	len = ft_strclen(s2, c);
	ret = ft_strnfjoin(s1, s2, len);
	return (ret);
}
