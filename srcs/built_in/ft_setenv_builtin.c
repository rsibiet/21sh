/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:35:55 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 14:35:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int			parse_var(char *str)
{
	int		i;

	i = 0;
	if (ft_isalpha(str[i]) == 0)
		return (0);
	i++;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static char			**get_perfect_split(char ***split_cmd)
{
	char	**tmp;

	if (ft_str_array_len(*split_cmd) == 3)
		return (*split_cmd);
	tmp = (char **)ft_memalloc(sizeof(char *) * 4);
	tmp[0] = ft_strdup((*split_cmd)[0]);
	tmp[1] = ft_strdup((*split_cmd)[1]);
	tmp[2] = ft_strdup("\0");
	ft_str_tab_del(split_cmd);
	return (tmp);
}

t_lst				*make_setenv(char ***split_cmd, t_lst *env)
{
	if (ft_str_array_len(*split_cmd) == 1)
		ft_disp_env(env);
	else
	{
		if (parse_var((*split_cmd)[1]))
		{
			*split_cmd = get_perfect_split(split_cmd);
			env = add_or_modif_env_elem(env, (*split_cmd)[1], (*split_cmd)[2]);
		}
		else
		{
			set_perror(NULL, NAME_WTHONLY_ALPHANUM_CHAR);
			return (NULL);
		}
	}
	return (env);
}

t_lst				*ft_setenv_builtin(char **cmd, t_lst *env)
{
	int			error;

	error = 0;
	if (ft_str_array_len(cmd) > 3)
	{
		set_perror(NULL, TOO_MANY_ARG);
		error = 1;
	}
	else
	{
		if (make_setenv(&cmd, env) == NULL)
			error = 1;
	}
	if (error)
		ft_perror(SETENV);
	return (env);
}
