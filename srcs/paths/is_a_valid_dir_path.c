/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_valid_dir_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:34:53 by mressier          #+#    #+#             */
/*   Updated: 2016/04/21 16:34:54 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
**	A valid path is a path:
**	- non-null
**	- non-empty
**	- who exist
**	- who is a directory
*/

int			is_a_valid_dir_path(char *str)
{
	struct stat		ret_stat;

	if (!str || str[0] == '\0')
		return (0);
	if (stat(str, &ret_stat) == -1)
		return (0);
	if (ft_get_file_mode(ret_stat.st_mode) != DIRECTORY)
		return (0);
	return (1);
}
