/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_host_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 18:09:48 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 18:09:49 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

static char		*ft_get_name_without_42(char **name)
{
	char		*new;
	char		*tmp;

	tmp = ft_strstr(*name, ".42.fr");
	if (tmp == NULL)
		return (*name);
	new = ft_cut_str(*name, tmp - *name, tmp - *name + ft_strlen(".42.fr"));
	ft_strdel(name);
	return (new);
}

char			*ft_get_host_name(void)
{
	char	*name;
	int		len;

	len = 300;
	name = ft_strnew(len);
	if (gethostname(name, len) == -1)
		name = ft_strdup("");
	else
		name = ft_get_name_without_42(&name);
	return (name);
}
