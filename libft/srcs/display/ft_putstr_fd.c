/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:38:51 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:20:31 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Put s on the file descriptor set in params
*/

#include "libz.h"

void	ft_putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
