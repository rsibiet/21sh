/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space_around_separator_char.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:43:02 by mressier          #+#    #+#             */
/*   Updated: 2016/05/07 14:43:05 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char			*ft_making_new(int i, int *start_cpy, char **cmd, char **new)
{
	if (i - 1 >= 0 && (*cmd)[i - 1] != ' '
			&& is_separator((*cmd)[i - 1]) == 0)
	{
		*new = ft_strnfjoin(new, &(*cmd)[*start_cpy], i - *start_cpy);
		*new = ft_strfjoin(new, " ");
		*start_cpy = i;
	}
	if ((*cmd)[i + 1] && (*cmd)[i + 1] != ' ')
	{
		*new = ft_strnfjoin(new, &(*cmd)[*start_cpy], i - *start_cpy + 1);
		*new = ft_strfjoin(new, " ");
		*start_cpy = i + 1;
	}
	return (*new);
}

char			*add_space_around_separator_char(char *cmd)
{
	int		i;
	int		start_cpy;
	char	*new;

	i = 0;
	start_cpy = i;
	new = ft_strnew(0);
	while (cmd[i])
	{
		if (is_separator(get_separator_char(cmd, i)))
		{
			new = ft_making_new(i, &start_cpy, &cmd, &new);
		}
		i++;
	}
	new = ft_strnfjoin(&new, &cmd[start_cpy], i - start_cpy);
	return (new);
}
