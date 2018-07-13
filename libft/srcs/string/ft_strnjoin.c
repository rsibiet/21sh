/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:57:11 by mressier          #+#    #+#             */
/*   Updated: 2016/02/03 10:41:27 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char		*ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	char	*dup_s2;
	char	*ret;

	dup_s2 = ft_strndup(s2, n);
	ret = ft_strjoin(s1, dup_s2);
	ft_strdel(&dup_s2);
	return (ret);
}
