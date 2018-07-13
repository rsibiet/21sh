/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_parse_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:24:20 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 19:24:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

#define EMPTY_ENV_FLAG 'i'
#define DEBUG_ENV_FLAG 'v'

static int		get_flags(int **flags, char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == EMPTY_ENV_FLAG)
			(*flags)[ENV_FLAG_I] = 1;
		else if (str[i] == DEBUG_ENV_FLAG)
			(*flags)[ENV_FLAG_V] = 1;
		else
		{
			usage_error(ENV, str[i]);
			return (-1);
		}
		i++;
	}
	return (1);
}

int				parse_flags_env(char **split_cmd, int *index, int **flags)
{
	int		i;

	i = 1;
	*flags = ft_intnew(NB_FLAGS);
	while (split_cmd[i] && split_cmd[i][0] == '-')
	{
		if (ft_strequ(split_cmd[i], "--"))
		{
			i++;
			break ;
		}
		else if (get_flags(flags, split_cmd[i]) == -1)
		{
			ft_memdel((void **)flags);
			return (-1);
		}
		i++;
	}
	*index = i;
	return (1);
}
