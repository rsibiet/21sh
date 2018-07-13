/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_21sh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:51:56 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/26 15:51:43 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libz.h"
#include <term.h>
#include "termcaps.h"

int			get_fd_prompt_sh(void)
{
	int		fd;
	char	*file;

	file = "/dev/tty";
	fd = open(file, O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd == -1)
		fd = 1;
	return (fd);
}

void		ft_putstr_intfd(char *str)
{
	int		fd;
	int		i;

	i = 0;
	fd = get_fd_prompt_sh();
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		if (str[i++] == '\n')
			tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	}
	if (fd > 2)
		close(fd);
}

void		ft_putstr_color_intfd(const char *color, const char *str)
{
	int		fd;

	fd = get_fd_prompt_sh();
	ft_putstr_color_fd(color, str, fd);
	if (fd > 2)
		close(fd);
}

int			ft_putchar_int(int c)
{
	int			fd;

	fd = get_fd_prompt_sh();
	ft_putchar_fd(c, fd);
	if (fd > 2)
		close(fd);
	return (1);
}
