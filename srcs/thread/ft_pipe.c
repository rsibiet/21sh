/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:35:23 by mressier          #+#    #+#             */
/*   Updated: 2016/05/18 10:35:25 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				ft_pipe(void)
{
	int		pipe_tab[2];
	int		pid;

	if (pipe(pipe_tab) == -1)
	{
		set_perror(NULL, PIPE_ERROR);
		return (-1);
	}
	pid = ft_fork();
	if (pid == CHILD)
	{
		dup2(pipe_tab[WRITE], STDOUT_FILENO);
		close(pipe_tab[READ]);
	}
	dup2(pipe_tab[READ], STDIN_FILENO);
	close(pipe_tab[WRITE]);
	return (pid);
}
