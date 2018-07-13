/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:44:11 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:20:05 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Put at most n char on the file descriptor set in params
*/

#include "libz.h"

void	ft_putnstr_fd(const char *s, size_t n)
{
	if (n < ft_strlen(s))
		write(1, s, n);
	else
		write(1, s, ft_strlen(s));
}
