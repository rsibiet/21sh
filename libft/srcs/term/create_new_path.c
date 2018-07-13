/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:51:06 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 11:51:07 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char		*get_new_path(const char *path, const char *to_add)
{
	char	*tmp;
	char	*result;

	tmp = ft_strdup(path);
	result = create_new_path(&tmp, to_add);
	return (result);
}

char		*create_new_path(char **path, const char *to_add)
{
	char	*new;
	int		len;

	len = ft_strlen(*path) + ft_strlen(to_add);
	if ((*path)[0] != '\0' && (*path)[ft_strlen(*path) - 1] != '/')
		len++;
	new = ft_strnew(len);
	new = ft_strcpy(new, *path);
	if (!ft_strequ(new, "") && (*path)[ft_strlen(*path) - 1] != '/'
			&& to_add[0] != '/' && to_add[0])
		new = ft_strcat(new, "/");
	new = ft_strcat(new, to_add);
	ft_strdel(path);
	return (new);
}
