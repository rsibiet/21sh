/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:19:45 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:12:03 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The strdup() function allocates sufficient memory for a copy of the
**	string s1, does the copy, and returns a pointer to it.
*/

#include "libz.h"

char	*ft_strdup(const char *s1)
{
	char	*new_s;

	new_s = ft_strnew(ft_strlen(s1));
	new_s = ft_strcpy(new_s, s1);
	return (new_s);
}
