/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_and_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 10:40:42 by mressier          #+#    #+#             */
/*   Updated: 2016/04/21 10:40:44 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
**	It return the command as the first string of the tab and args follows
**	If there is no command, it returns null
*/

static char		**cut_quote(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab && tab[i])
	{
		tmp = delete_quote(tab[i]);
		ft_str_replace_str(&tab[i], tmp);
		i++;
	}
	return (tab);
}

char			**get_cmd_and_argv(char *str)
{
	char	**result;

	result = NULL;
	if (str && str[0])
		result = sh_strsplit(str, ' ');
	if (!result || result[0] == NULL || result[0][0] == '\0')
		ft_str_tab_del(&result);
	else
		result = cut_quote(result);
	return (result);
}
