/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:16:36 by mressier          #+#    #+#             */
/*   Updated: 2016/04/27 16:16:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char				*ft_cut_str(char *str, int start, int end)
{
	char	*new_str;

	if (start < 0 || end < 0 || start > end
			|| (size_t)start > ft_strlen(str)
			|| (size_t)end > ft_strlen(str))
		return (NULL);
	new_str = ft_strndup(str, start);
	if (str[end] && str[end + 1])
		new_str = ft_strfjoin(&new_str, &str[end + 1]);
	return (new_str);
}
