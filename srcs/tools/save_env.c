/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:49:12 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 12:49:13 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_lst		*save_env(t_lst *env)
{
	static t_lst	*save = NULL;

	if (env)
		save = env;
	return (save);
}

t_lst				*get_save_env(void)
{
	return (save_env(NULL));
}

void				set_save_env(t_lst *lst)
{
	save_env(lst);
}
