/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 10:27:37 by mressier          #+#    #+#             */
/*   Updated: 2016/04/21 10:27:39 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int		nb_of_valid_paths(char **paths)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (paths[i])
	{
		if (is_a_valid_dir_path(paths[i]))
			n++;
		i++;
	}
	return (n);
}

static char		**cpy_only_valid_paths(char **tmp_paths, int valid_paths)
{
	char	**path_tab;
	int		i;
	int		j;

	i = 0;
	j = 1;
	path_tab = (char **)ft_memalloc(sizeof(char *) * (valid_paths + 2));
	path_tab[0] = ft_strdup("");
	while (tmp_paths[i])
	{
		if (is_a_valid_dir_path(tmp_paths[i]))
		{
			path_tab[j] = ft_strdup(tmp_paths[i]);
			j++;
		}
		i++;
	}
	path_tab[j] = NULL;
	return (path_tab);
}

/*
**  	------------------------------------------------------
**  	|						MAIN		         	     |
**  	------------------------------------------------------
*/

char			**get_valid_paths(t_lst *env)
{
	char	*paths;
	char	**tmp_path_tab;
	char	**path_tab;
	int		nb;

	paths = get_env_elem_content(env, "PATH");
	if (paths == NULL)
		paths = ft_strdup("");
	tmp_path_tab = ft_strsplit(paths, ':');
	nb = nb_of_valid_paths(tmp_path_tab);
	path_tab = cpy_only_valid_paths(tmp_path_tab, nb);
	ft_str_tab_del(&tmp_path_tab);
	ft_strdel(&paths);
	return (path_tab);
}
