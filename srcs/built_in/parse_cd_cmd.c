/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cd_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 12:35:14 by mressier          #+#    #+#             */
/*   Updated: 2016/04/27 12:35:15 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int		get_cd_flag(char *str, int *flags)
{
	int		i;

	i = 1;
	while (str[i])
	{
		*flags = str[i];
		if (str[i] != 'P' && str[i] != 'L')
			return (-1);
		i++;
	}
	return (1);
}

int				parse_cd_cmd_split(char **split_cmd, int *flags, int *index)
{
	int		i;

	i = 1;
	while (split_cmd[i] && split_cmd[i][0] == '-' && split_cmd[i][1])
	{
		if (ft_strequ(split_cmd[i], "--"))
		{
			i++;
			break ;
		}
		else if (get_cd_flag(split_cmd[i], flags) == -1)
			return (-1);
		i++;
	}
	*index = i;
	if (ft_str_array_len(&split_cmd[i]) > 1)
		return (-1);
	return (1);
}
