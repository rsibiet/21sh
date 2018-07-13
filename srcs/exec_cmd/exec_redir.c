/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 10:00:40 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 14:47:44 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <fcntl.h>

static int			do_redir(int fd, int redir)
{
	int			ret;
	char		*s_fd;

	if (fd == -1 || redir == -1)
		return (-1);
	ret = dup2(fd, redir);
	if (ret == -1)
	{
		s_fd = ft_itoa(fd);
		set_perror(s_fd, BAD_FD);
		ft_strdel(&s_fd);
	}
	return (ret);
}

int					exec_redir(t_bin *branch, t_core *core)
{
	int		ret;
	int		fd;
	int		redir;
	int		flags;

	ret = 0;
	if (branch->ope == DB_REDIR_LEFT)
		heredoc(branch, core);
	else
	{
		flags = get_redir_open_flags(branch->ope);
		fd = get_fd(branch, flags);
		redir = get_redir(branch);
		ret = do_redir(fd, redir);
	}
	if (ret == -1)
		ft_perror(SHELL);
	else
	{
		exec_bin_tree(branch->left, core);
		exit(1);
	}
	if (ret > 2)
		close(ret);
	return (ret);
}
