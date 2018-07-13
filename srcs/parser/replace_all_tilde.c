/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_all_tilde.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 11:38:49 by mressier          #+#    #+#             */
/*   Updated: 2016/05/17 12:33:46 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char			*get_new_char(int *count, char *str, t_lst *env)
{
	char		*tmp;

	tmp = NULL;
	if (ft_count_char(str, DB_QUOTE) % 2 != 0)
		*count = *count > 0 ? 0 : 1;
	if (*count == 0 && (tmp = get_tilde_and_replace(str, env)) == NULL)
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	else if (*count)
		tmp = ft_strdup(str);
	return (tmp);
}

char				*replace_all_tilde(char **cmd, t_lst *env)
{
	char	**split;
	char	*new_cmd;
	char	*tmp;
	int		i;
	int		count;

	i = 0;
	split = ft_explode(*cmd, ' ');
	count = 0;
	while (split[i])
	{
		tmp = get_new_char(&count, split[i], env);
		if (tmp == NULL)
		{
			ft_str_tab_del(&split);
			return (NULL);
		}
		ft_str_replace_str(&split[i], tmp);
		i++;
	}
	new_cmd = ft_implode(split, ' ');
	ft_strdel(cmd);
	ft_str_tab_del(&split);
	return (new_cmd);
}
