/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:49:02 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:12:20 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Create a new string by concatenate s1-s2 and then free the first string
*/

#include "libz.h"

char	*ft_strfjoin(char **s1, const char *s2)
{
	char	*new_str;
	char	*dup_s1;

	dup_s1 = ft_strdup(*s1);
	new_str = ft_strjoin(dup_s1, s2);
	ft_strdel(&dup_s1);
	ft_strdel(s1);
	return (new_str);
}
