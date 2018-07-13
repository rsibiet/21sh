/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_env_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:07:06 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 19:07:07 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_lst			*modif_env_elem(t_lst *lst_env, const char *name,
					const char *content)
{
	t_lst	*cur;

	cur = get_env_elem(lst_env, name);
	if (cur)
	{
		ft_str_replace_str(((char **)&((t_env *)cur->data)->content),
			ft_strdup(content));
		return (lst_env);
	}
	return (NULL);
}

t_lst			*add_or_modif_env_elem(t_lst *lst_env, const char *name,
					const char *content)
{
	t_lst	*new;

	if ((new = modif_env_elem(lst_env, name, content)) == NULL)
		new = add_env_elem(lst_env, name, content);
	return (new);
}
