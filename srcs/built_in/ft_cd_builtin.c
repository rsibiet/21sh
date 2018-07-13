/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 12:15:51 by mressier          #+#    #+#             */
/*   Updated: 2016/04/27 12:15:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_lst		*make_move(char *cmd_dir, t_lst *env, int flag)
{
	char	*dir;
	t_lst	*tmp;

	dir = parse_cd_dir(cmd_dir, env, flag);
	if (dir)
	{
		tmp = move_dir(cmd_dir, dir, env, flag);
		if (tmp == NULL)
		{
			if (!cmd_dir || !cmd_dir[0] || ft_strequ(cmd_dir, "-"))
				set_perror(dir, PERM_DENIED);
			else
				set_perror(cmd_dir, PERM_DENIED);
			ft_perror(CD);
		}
		else
			env = tmp;
	}
	else
		ft_perror(CD);
	ft_strdel(&dir);
	return (env);
}

t_lst				*ft_cd_builtin(char **cmd, t_lst *env)
{
	int		flag;
	int		index;

	flag = 0;
	if (parse_cd_cmd_split(cmd, &flag, &index) == -1)
	{
		(flag != 'P' && flag != 'L' && flag != 0) ? usage_error(CD, flag) :
			ft_puterror_twopart(CD, "Too many arguments", NULL);
	}
	else
		env = make_move(cmd[index], env, flag);
	return (env);
}
