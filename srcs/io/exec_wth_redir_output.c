/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_wth_redir_output.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:27:08 by mressier          #+#    #+#             */
/*   Updated: 2016/05/11 11:27:10 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				exec_with_redirect_output(const char *filename, int flags,
					char *cmd)
{
	int			fd;
	int			child;

	child = -1;
	fd = open(filename, flags, 0644);
	if (fd == -1)
	{
		set_perror(filename, NO_FILE_OR_DIR);
		return (-1);
	}
}
