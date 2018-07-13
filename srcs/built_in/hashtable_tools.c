/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 17:51:08 by mressier          #+#    #+#             */
/*   Updated: 2016/05/24 17:51:09 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "termcaps.h"
#include <dirent.h>

int					is_doublon(char **htable)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (htable && htable[i] && htable[i + 1])
	{
		if (cmp_values(htable[i], htable[i + 1], is_equal))
		{
			ft_putstr(htable[i]);
			ft_putstr(" with ");
			ft_putendl(htable[i + 1]);
			nb++;
		}
		i++;
	}
	return (nb);
}

int					disp_hashtable(char **hashtable)
{
	int				i;
	char			**split_hash;

	i = 0;
	while (hashtable && hashtable[i])
	{
		split_hash = ft_strsplit_once(hashtable[i], ' ');
		ft_putstr("key : {\t");
		ft_putstr_color(C_RED, split_hash[0]);
		ft_putstr(" }\t; value : { ");
		ft_putstr_color(C_PURPLE, split_hash[1]);
		ft_putstr(" }\n");
		ft_str_tab_del(&split_hash);
		i++;
	}
	ft_putnbr_color(C_G_GREEN, i);
	ft_putendl(" binaries.");
	return (i);
}

static int			get_nb_bin_in_paths(char **paths)
{
	int		i;
	int		len;
	DIR		*pt_dir;
	t_lst	*lst_content;

	i = 1;
	len = 0;
	lst_content = NULL;
	while (paths && paths[i])
	{
		if ((pt_dir = opendir(paths[i])) != NULL)
		{
			lst_content = create_list_with_dir_content(pt_dir, paths[i]);
			len += ft_lst_len(lst_content);
			ft_lst_del(&lst_content, (void (*)(void **))ft_strdel);
			closedir(pt_dir);
		}
		i++;
	}
	return (len);
}

char				*hashtool(const char *str)
{
	unsigned long long int	hash;
	int						i;

	i = 0;
	hash = 0;
	while (str[i])
	{
		hash += str[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
		i++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (ft_llitoa_base(hash, 10));
}

char				**malloc_hashtable(char **paths)
{
	int			len;
	char		**htable;

	len = get_nb_bin_in_paths(paths);
	if (len == 0)
		htable = NULL;
	else
		htable = (char **)ft_memalloc(sizeof(char *) * (len + 1));
	return (htable);
}
