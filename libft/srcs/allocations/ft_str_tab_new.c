/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tab_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:01:21 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:14:00 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char		**ft_str_tab_new(size_t nb_str, size_t size_str)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_memalloc(sizeof(char *) * (nb_str + 1));
	while ((size_t)i < nb_str)
	{
		str[i] = ft_strnew(size_str);
		i++;
	}
	return (str);
}
