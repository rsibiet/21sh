/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:28:28 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 16:28:31 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_lst		*add_env_elem(t_lst *list, const char *name, const char *content)
{
	t_env		*new;

	if (get_env_elem(list, name))
		return (NULL);
	new = create_env_elem(name, content);
	if (list == NULL)
		return (ft_lst_new(new));
	return (ft_lst_add_end(ft_lst_new(new), list));
}
