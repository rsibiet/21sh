/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tilde_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:53:06 by mressier          #+#    #+#             */
/*   Updated: 2016/04/27 10:53:08 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

/*
**	return 0 if there is not tilde
**	return -1 if they can't replace by home
*/

char			*get_tilde_and_replace(char *cmd, t_lst *env)
{
	char	*new;
	char	*home;

	if (!cmd)
		return (ft_strdup(""));
	if (*cmd != '~' || (*cmd == '~' && cmd[1] && cmd[1] != '/'))
		return (ft_strdup(cmd));
	home = get_env_elem_content(env, "HOME");
	if (home == NULL)
		return (NULL);
	new = ft_search_and_replace_char(cmd, home, '~');
	ft_strdel(&home);
	return (new);
}
