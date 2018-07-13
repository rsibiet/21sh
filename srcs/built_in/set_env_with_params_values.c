/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_duo_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:10:32 by mressier          #+#    #+#             */
/*   Updated: 2016/04/28 17:10:34 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int			error(const char *str)
{
	char		*str_tmp;

	str_tmp = ft_strjoin("setenv ", str);
	set_perror(str_tmp, INVALID_ARG);
	ft_strdel(&str_tmp);
	return (-1);
}

static char			**get_duo_value(const char *str)
{
	char	**duo_value;
	char	*tmp;

	duo_value = ft_strsplit_once(str, '=');
	if (duo_value && duo_value[0][0] != '\0')
	{
		if (duo_value[1][0] == '=')
		{
			tmp = ft_cut_str(duo_value[1], 0, 0);
			ft_str_replace_str(&duo_value[1], tmp);
		}
	}
	else
	{
		ft_str_tab_del(&duo_value);
		return (NULL);
	}
	return (duo_value);
}

static int			set_env(const char *str, t_lst **env, int *flags)
{
	char	**duo_value;
	int		ret;

	duo_value = get_duo_value(str);
	ret = 1;
	if (duo_value == NULL)
		ret = -1;
	if (flags[ENV_FLAG_V])
		prompt_opt_v_env(SETENV, str, NULL);
	if (ret != -1)
		*env = add_or_modif_env_elem(*env, duo_value[0], duo_value[1]);
	ft_str_tab_del(&duo_value);
	return (ret);
}

int					set_env_with_param_values(char **split_cmd, t_lst **env,
						int *index, int *flags)
{
	int		i;
	int		ret;

	i = *index;
	while (split_cmd[i] && ft_strchr(split_cmd[i], '='))
	{
		ret = set_env(split_cmd[i], env, flags);
		if (ret == -1)
			return (error(split_cmd[i]));
		i++;
	}
	*index = i;
	return (1);
}
