/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:21:00 by mressier          #+#    #+#             */
/*   Updated: 2016/05/23 10:21:02 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void			error(int ope)
{
	char		*error;

	if (ope == DB_REDIR_RIGHT || ope == DB_REDIR_LEFT)
		error = ft_strdup(ope == DB_REDIR_RIGHT ? "`>>'" : "`<<'");
	else if (ope == REDIR_RIGHT_ET || ope == REDIR_LEFT_ET)
		error = ft_strdup(ope == REDIR_RIGHT_ET ? "`>&'" : "`<&'");
	else
		error = ft_strdup(ope == REDIR_RIGHT ? "`>'" : "`<'");
	set_perror(error, PARSING_ERROR);
	ft_strdel(&error);
}

static char			*get_name(char *str, int pos, int ope)
{
	char			*new;
	int				start;
	int				end;

	if (ope == REDIR_RIGHT_ET || ope == REDIR_LEFT_ET)
		start = pos + 2;
	else
		start = pos + 1;
	end = get_end_cmd(str, start);
	new = ft_strsub(str, start, end - start + 1);
	ft_str_replace_str(&new, sh_strintrim(new));
	if ((ope == REDIR_LEFT_ET && ft_str_is_only_digit(new) == 0
			&& ft_strequ(new, "-") == 0 && new[0]))
	{
		set_perror(NULL, FILE_NB_EXPECT);
		ft_strdel(&new);
	}
	return (new);
}

static char			*get_output_fd(char *str, int i, int ope)
{
	char		*new_s;

	new_s = ft_strnew(1);
	i--;
	if (ope == DB_REDIR_LEFT || ope == DB_REDIR_RIGHT)
		i--;
	while (i >= 0)
	{
		if (ft_isdigit(str[i]) && (i - 1 < 0 || ft_isspace(str[i - 1])))
		{
			new_s[0] = str[i];
			break ;
		}
		else if (ft_isspace(str[i]) == 0)
			break ;
		i--;
	}
	return (new_s);
}

char				*get_output_name(char *str, int pos, int ope)
{
	char			*new;
	char			*name;
	char			*fd;

	name = get_name(str, pos, ope);
	if (name == NULL)
		return (NULL);
	fd = get_output_fd(str, pos, ope);
	new = ft_strfjoin(&fd, " ");
	new = ft_strfjoin(&new, name);
	ft_strdel(&name);
	if (ft_strequ(new, " ") || new[ft_strlen(new) - 1] == ' ')
	{
		ft_strdel(&new);
		error(ope);
	}
	return (new);
}
