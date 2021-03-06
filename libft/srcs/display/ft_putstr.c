/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:38:24 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:20:20 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}
