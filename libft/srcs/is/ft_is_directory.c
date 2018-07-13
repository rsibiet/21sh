/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 12:36:45 by mressier          #+#    #+#             */
/*   Updated: 2016/04/27 12:36:47 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int					ft_is_sym_link(const char *pathname)
{
	struct stat		ret_stat;

	if (stat(pathname, &ret_stat) == -1)
		return (0);
	if (ft_get_file_mode(ret_stat.st_mode) != SYM_LINK)
		return (0);
	return (1);
}

int					ft_is_directory(const char *pathname)
{
	struct stat		ret_stat;

	if (stat(pathname, &ret_stat) == -1)
		return (0);
	if (ft_get_file_mode(ret_stat.st_mode) != DIRECTORY)
		return (0);
	return (1);
}
