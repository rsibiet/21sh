/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:29:52 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:20:26 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void		ft_putnbr_color(const char *color, int n)
{
	ft_putstr(color);
	ft_putnbr(n);
	ft_putstr("\033[0m");
}

void		ft_putstr_color_fd(const char *color, const char *s, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\033[0m", fd);
	if (fd > 2)
		close(fd);
}

void		ft_putstr_color(const char *color, const char *s)
{
	ft_putstr(color);
	ft_putstr(s);
	ft_putstr("\033[0m");
}
