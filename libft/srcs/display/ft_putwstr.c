/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:54:34 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:20:42 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Put an array of wchar_t
*/

#include "libz.h"

void		ft_putwstr(const wchar_t *ws)
{
	int		tmp;

	tmp = 0;
	while (*ws)
	{
		if ((tmp = ft_putwchar(*ws)) == -1)
			ft_puterror("Can't print this...");
		ws++;
	}
}
