/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:18:15 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 15:18:16 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_lst				*del_lst_elem_by_name(t_lst *env, const char *name)
{
	t_lst	*cur;
	t_lst	*to_del;
	t_lst	*tmp;

	cur = env;
	if (!cur)
		return (env);
	if (ft_strequ(((char *)((t_env *)cur->data)->name), name))
	{
		env = cur->next;
		del_env_elem((t_env **)&cur->data);
		return (env);
	}
	while (cur->next && ft_strequ(((char *)((t_env *)cur->next->data)->name),
			name) == 0)
		cur = cur->next;
	if (cur && cur->next
			&& ft_strequ(((char *)((t_env *)cur->next->data)->name), name))
	{
		tmp = cur->next->next;
		to_del = cur->next;
		ft_lst_del_one(&to_del, (void (*)(void **))del_env_elem);
		cur->next = tmp;
	}
	return (env);
}

void				del_lst_env(t_lst **env)
{
	ft_lst_del(env, (void (*)(void **))del_env_elem);
}

void				del_env_elem(t_env **elem)
{
	if (elem && *elem)
	{
		ft_strdel(&((*elem)->name));
		ft_strdel(&((*elem)->content));
		ft_memdel((void **)elem);
	}
}
