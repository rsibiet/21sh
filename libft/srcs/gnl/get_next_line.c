/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 18:58:47 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:20:46 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_full_line(char **line, char **str_fd, int fd)
{
	int		ret;
	char	*tmp;
	char	*buf_read;

	buf_read = ft_strdup(str_fd[fd]);
	while (ft_strchr(buf_read, '\n') == NULL)
	{
		*line = ft_strfjoin(line, buf_read);
		ft_strdel(&buf_read);
		buf_read = ft_strnew(BUFF_SIZE);
		if ((ret = read(fd, buf_read, BUFF_SIZE)) <= 0)
		{
			ft_strdel(&buf_read);
			if (ret == -1)
				return (-1);
			else
				return (**line == '\0' ? 0 : 1);
		}
	}
	*line = ft_strcfjoin(line, buf_read, '\n');
	tmp = ft_strdup(ft_strchr(buf_read, '\n') + 1);
	ft_strdel(&buf_read);
	ft_strdel(&(str_fd[fd]));
	str_fd[fd] = tmp;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char	*str_fd[MAX_FD];
	int			ret_read;

	if (line == NULL || (*line = ft_strnew(0)) == NULL
		|| fd < 0 || fd > MAX_FD)
		return (-1);
	if (str_fd[fd] == NULL)
		if ((str_fd[fd] = ft_strnew(0)) == NULL)
			return (-1);
	ret_read = get_full_line(line, str_fd, fd);
	return (ret_read);
}
