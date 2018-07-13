/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commande.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:29:10 by mressier          #+#    #+#             */
/*   Updated: 2016/05/17 12:11:21 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char			*error(const char *str)
{
	ft_puterror(str);
	return (NULL);
}

static void			trim_cmd(char **cmd)
{
	char		*tmp;

	tmp = sh_strintrim(*cmd);
	ft_str_replace_str(cmd, tmp);
}

char				*parse_commande(char **cmd, t_lst *env)
{
	char	*new_cmd;
	char	*new_tmp;

	trim_cmd(cmd);
	new_cmd = replace_all_dollar_var_by_env_var(cmd, env);
	if (new_cmd == NULL)
		return (error(": Undefined variable\n"));
	new_tmp = replace_all_tilde(&new_cmd, env);
	if (new_tmp == NULL)
	{
		ft_strdel(&new_cmd);
		return (error("No $home variable set\n"));
	}
	else
		new_cmd = new_tmp;
	return (new_cmd);
}
