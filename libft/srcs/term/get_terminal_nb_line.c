/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terminal_nb_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 14:24:13 by mressier          #+#    #+#             */
/*   Updated: 2016/03/16 16:12:41 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

size_t		get_terminal_nb_line(void)
{
	struct winsize	w;
	size_t			ret;

	ioctl(0, TIOCGWINSZ, &w);
	ret = w.ws_row;
	return (ret);
}
