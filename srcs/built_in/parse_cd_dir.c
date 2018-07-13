/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cd_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:11:17 by mressier          #+#    #+#             */
/*   Updated: 2016/04/28 18:11:18 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int		check_error(char **dir, char *cmd)
{
	if (ft_is_existing_file(*dir) && ft_is_directory(cmd))
		return (0);
	if (ft_is_existing_file(*dir) == 0)
		set_perror(cmd, NO_FILE_OR_DIR);
	else if (ft_is_directory(*dir) == 0)
		set_perror(cmd, NOT_DIR);
	ft_strdel(dir);
	return (1);
}

char			*normal_path(char *cmd, int flag, t_lst *env)
{
	char		*dir;

	dir = cd_create_dir(cmd, flag, env);
	if (check_error(&dir, cmd))
		return (NULL);
	return (dir);
}

char			*parse_cd_dir(char *cmd, t_lst *env, int flag)
{
	char	*dir;

	if (!cmd || !cmd[0])
	{
		dir = get_env_elem_content(env, "HOME");
		if (dir == NULL)
			set_perror(NULL, NO_HOME_DIR);
	}
	else if (ft_strequ(cmd, "-"))
	{
		dir = get_env_elem_content(env, "OLDPWD");
		if (dir == NULL)
			set_perror(NULL, NO_PREVIOUS_DIR);
	}
	else
		return (normal_path(cmd, flag, env));
	if (dir == NULL || check_error(&dir, dir))
		return (NULL);
	return (dir);
}
