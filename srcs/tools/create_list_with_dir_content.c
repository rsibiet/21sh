/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_with_dir_content.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 19:13:12 by mressier          #+#    #+#             */
/*   Updated: 2016/03/04 19:13:13 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libz.h"

static int	stc_keep_file(char *path, char *filename)
{
	if (ft_is_exec_file(path) && *filename != '.')
		return (1);
	return (0);
}

t_lst		*create_list_with_dir_content(DIR *dirp, const char *path)
{
	t_lst			*dir_list;
	t_lst			*tmp;
	struct dirent	*ret_read;
	int				count;
	char			*tmp_path;

	dir_list = NULL;
	count = 0;
	while ((ret_read = readdir(dirp)))
	{
		tmp_path = get_new_path(path, ret_read->d_name);
		if (stc_keep_file(tmp_path, ret_read->d_name))
		{
			tmp = ft_lst_new(ft_strdup(tmp_path));
			if (tmp && tmp->data)
				dir_list = ft_lst_add_end(tmp, dir_list);
		}
		ft_strdel(&tmp_path);
		count++;
	}
	return (dir_list);
}
