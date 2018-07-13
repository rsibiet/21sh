/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd_redir_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:57:20 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 14:42:43 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <fcntl.h>

static char			**get_split_redir(t_bin *branch)
{
	char			**split_redir;

	split_redir = ft_strsplit_once(branch->right->cmd, ' ');
	if (ft_strequ(split_redir[1], "-") &&
			(branch->ope == REDIR_RIGHT_ET || branch->ope == REDIR_LEFT_ET))
		ft_str_replace_str(&split_redir[1], ft_strdup("/dev/null"));
	ft_str_replace_str(&split_redir[1], delete_quote(split_redir[1]));
	return (split_redir);
}

int					get_fd(t_bin *branch, int flags)
{
	char		**split_redir;
	int			fd;

	split_redir = get_split_redir(branch);
	if (ft_str_is_only_digit(split_redir[1]) &&
			(branch->ope == REDIR_RIGHT_ET || branch->ope == REDIR_LEFT_ET))
		fd = ft_atoi(split_redir[1]);
	else
		fd = open(split_redir[1], flags, 0644);
	if (fd == -1)
		set_perror(split_redir[1], NO_FILE_OR_DIR);
	ft_str_tab_del(&split_redir);
	return (fd);
}

int					get_redir(t_bin *branch)
{
	char		**split_redir;
	int			redir;

	split_redir = get_split_redir(branch);
	redir = 0;
	if (split_redir[0][0] == '\0')
	{
		if (branch->ope == REDIR_RIGHT
				|| branch->ope == REDIR_RIGHT_ET
				|| branch->ope == DB_REDIR_RIGHT
				|| branch->ope == DB_REDIR_LEFT)
			redir = STDOUT_FILENO;
		else if (branch->ope == REDIR_LEFT || branch->ope == REDIR_LEFT_ET)
			redir = STDIN_FILENO;
	}
	else
		redir = ft_atoi(split_redir[0]);
	ft_str_tab_del(&split_redir);
	return (redir);
}

int					get_redir_open_flags(int ope)
{
	if (ope == REDIR_RIGHT || ope == REDIR_RIGHT_ET)
		return (O_WRONLY | O_CREAT | O_TRUNC);
	else if (ope == REDIR_LEFT || ope == REDIR_LEFT_ET)
		return (O_RDONLY);
	else if (ope == DB_REDIR_RIGHT)
		return (O_WRONLY | O_CREAT | O_APPEND);
	else
		return (0);
}
