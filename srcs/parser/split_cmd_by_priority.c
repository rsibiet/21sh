/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_by_priority.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 14:27:43 by mressier          #+#    #+#             */
/*   Updated: 2016/05/17 10:37:30 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int			error_case(t_lst **all_cmd, char ***split_cmd, int i)
{
	if (!(*split_cmd)[i]
			|| ((*split_cmd)[i][0] == 0 && (*split_cmd)[i + 1] && i != 0))
	{
		ft_lst_del(all_cmd, (void (*)(void **))ft_strdel);
		ft_str_tab_del(split_cmd);
		return (1);
	}
	return (0);
}

t_lst				*split_cmd_by_priority(char *cmd)
{
	t_lst		*all_cmd;
	t_lst		*tmp;
	char		**split_cmd;
	int			i;

	all_cmd = NULL;
	split_cmd = ft_explode(cmd, ';');
	i = ft_str_array_len(split_cmd) - 1;
	while (i >= 0)
	{
		if (error_case(&all_cmd, &split_cmd, i))
			return (NULL);
		tmp = ft_lst_new(ft_strdup(split_cmd[i]));
		if (is_exit_builtin(split_cmd[i]))
			all_cmd = ft_lst_add_end(tmp, all_cmd);
		else
			all_cmd = ft_lst_add(tmp, all_cmd);
		i--;
	}
	ft_str_tab_del(&split_cmd);
	return (all_cmd);
}
