/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exec_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 17:07:00 by mressier          #+#    #+#             */
/*   Updated: 2016/04/21 17:07:02 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int		ft_is_exec_file(const char *pathname)
{
	struct stat		ret_stat;

	if (ft_is_directory(pathname))
		return (0);
	if (stat(pathname, &ret_stat) != -1)
	{
		if ((ret_stat.st_mode & S_IXOTH) || (ret_stat.st_mode & S_IXGRP)
				|| (ret_stat.st_mode & S_IXUSR))
			return (1);
	}
	return (0);
}
