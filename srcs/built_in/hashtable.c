/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 17:45:07 by mressier          #+#    #+#             */
/*   Updated: 2016/05/24 17:45:09 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "termcaps.h"

static char				**fill_hashtable(t_lst *dir_content, char **htable)
{
	t_lst			*cur;
	int				j;
	char			*tmp;
	char			*dir;

	j = 0;
	cur = dir_content;
	while (htable && htable[j])
		j++;
	while (cur)
	{
		dir = cur->data;
		if (dir[0] == '/' && ft_count_char(dir, '/') == 1)
			;
		else
			dir = ft_strrchr(dir, '/') + 1;
		tmp = hashtool((char *)dir);
		tmp = ft_strfjoin(&tmp, " ");
		htable[j] = ft_strjoin(tmp, (char *)dir);
		ft_strdel(&tmp);
		j++;
		cur = cur->next;
	}
	return (htable);
}

static char				**complete_hashtable(char **paths, char **htable)
{
	int		i;
	DIR		*pt_dir;
	t_lst	*lst_content;

	i = 1;
	lst_content = NULL;
	while (paths && paths[i])
	{
		if ((pt_dir = opendir(paths[i])) != NULL)
		{
			lst_content = create_list_with_dir_content(pt_dir, paths[i]);
			htable = fill_hashtable(lst_content, htable);
			ft_lst_del(&lst_content, (void (*)(void **))ft_strdel);
			closedir(pt_dir);
		}
		i++;
	}
	return (htable);
}

static char				**create_hashtable(t_lst *env)
{
	char		**paths;
	char		**htable;

	paths = get_valid_paths(env);
	htable = malloc_hashtable(paths);
	if (htable)
		htable = complete_hashtable(paths, htable);
	ft_str_tab_del(&paths);
	return (htable);
}

char					**get_hashtable(t_lst *env)
{
	char			**htable;

	htable = create_hashtable(env);
	htable = sort_hashtable(htable);
	return (htable);
}

int						ft_builtin_hashtable(t_lst *env)
{
	char				**hashtable;
	int					ret;

	ret = 1;
	hashtable = get_hashtable(env);
	if (disp_hashtable(hashtable) == 0)
		ret = -1;
	ft_str_tab_del(&hashtable);
	return (ret);
}
