/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 13:14:16 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:12:44 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Take two string and create a new string by concatenate s1-s2
*/

#include "libz.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;

	new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	new_str = ft_strcpy(new_str, s1);
	new_str = ft_strcat(new_str, s2);
	return (new_str);
}
