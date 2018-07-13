/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:00:50 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 16:00:51 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char	**create_str_env(t_lst *env)
{
	t_lst	*cur;
	char	*tmp;
	int		i;
	char	**environ;

	i = 0;
	cur = env;
	environ = (char **)ft_memalloc(sizeof(char *) * (ft_lst_len(env) + 1));
	while (cur)
	{
		tmp = ft_strjoin(((char *)((t_env *)cur->data)->name), "=");
		environ[i] = ft_strfjoin(&tmp, ((char *)((t_env *)cur->data)->content));
		cur = cur->next;
		i++;
	}
	return (environ);
}
