/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:08:36 by mressier          #+#    #+#             */
/*   Updated: 2016/04/25 18:08:38 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

static int			count_total_len(char **str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += ft_strlen(str[i]);
		i++;
	}
	return (len);
}

char				*ft_implode(char **str, int c)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = count_total_len(str);
	len += ft_str_array_len(str) - 1;
	len = (len < 0) ? 0 : len;
	new_str = ft_strnew(len);
	while (str[i])
	{
		new_str = ft_strcat(new_str, str[i]);
		i++;
		if (str[i])
			new_str = ft_str_concat_char(new_str, c);
	}
	return (new_str);
}
