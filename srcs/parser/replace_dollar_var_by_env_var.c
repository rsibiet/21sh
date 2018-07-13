/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_var_by_env_var.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:34:07 by mressier          #+#    #+#             */
/*   Updated: 2016/04/28 16:50:11 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char			*replace_dollar_var_by_env_var(char *str, int *pos,
							const char *var, t_lst *env)
{
	char		*tmp;
	char		*new_cmd;

	tmp = get_env_elem_content(env, &var[1]);
	if (tmp)
	{
		new_cmd = ft_str_replace_in_str(str, var, tmp, *pos);
		(*pos) += ft_strlen(tmp) - 1;
		ft_strdel(&tmp);
		return (new_cmd);
	}
	else
	{
		ft_puterror(&var[1]);
		return (NULL);
	}
}

static char			*stc_modif_str(char *str, int *i, char *to_rep, t_lst *env)
{
	char			*tmp;

	tmp = replace_dollar_var_by_env_var(str, i, to_rep, env);
	if (tmp)
		ft_str_replace_str(&str, tmp);
	else
		str = NULL;
	return (str);
}

static char			*get_new_str_without_dollar_var(char *str, t_lst *env)
{
	char			*to_replace;
	int				i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '$')
		{
			to_replace = get_var_in_dollar_var(str, i);
			if (to_replace)
			{
				str = stc_modif_str(str, &i, to_replace, env);
				ft_strdel(&to_replace);
			}
		}
		i++;
	}
	return (str);
}

char				*replace_all_dollar_var_by_env_var(char **cmd, t_lst *env)
{
	char	**split;
	char	*tmp;
	char	*new_cmd;
	int		i;

	i = 0;
	split = ft_explode(*cmd, ' ');
	ft_strdel(cmd);
	while (split[i])
	{
		tmp = get_new_str_without_dollar_var(split[i], env);
		if (tmp == NULL)
		{
			ft_str_tab_del(&split);
			return (NULL);
		}
		split[i] = tmp;
		i++;
	}
	new_cmd = ft_implode(split, ' ');
	ft_str_tab_del(&split);
	return (new_cmd);
}
