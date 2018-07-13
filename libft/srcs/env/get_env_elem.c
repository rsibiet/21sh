/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_elem_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:23:02 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 17:23:04 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char	*get_env_elem_content(t_lst *env, const char *name)
{
	t_lst	*get;
	char	*content;

	get = get_env_elem(env, name);
	content = NULL;
	if (get)
		content = ft_strdup(((char *)((t_env *)get->data)->content));
	return (content);
}

t_lst	*get_env_elem(t_lst *env, const char *name)
{
	t_lst	*cur;
	t_lst	*ptr;

	cur = env;
	ptr = NULL;
	while (cur)
	{
		if (ft_strequ(((char *)((t_env *)cur->data)->name), name))
		{
			ptr = cur;
			break ;
		}
		cur = cur->next;
	}
	return (ptr);
}
