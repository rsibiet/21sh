/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:32:57 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 14:32:59 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_env		*create_env_elem(const char *name, const char *content)
{
	t_env	*env;

	if (name[0] == '\0')
		return (NULL);
	env = (t_env *)ft_memalloc(sizeof(t_env));
	env->name = ft_strdup(name);
	env->content = ft_strdup(content);
	return (env);
}

t_env		*create_env_elem_by_split(char *str)
{
	char	**result_split;
	t_env	*env;

	result_split = ft_strsplit_once(str, '=');
	if (result_split[0] && result_split[1])
		env = create_env_elem(result_split[0], result_split[1]);
	else
		env = NULL;
	ft_str_tab_del(&result_split);
	return (env);
}
