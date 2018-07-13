/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror_twopart.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:24:11 by mressier          #+#    #+#             */
/*   Updated: 2016/04/23 11:24:13 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		ft_puterror_twopart(const char *s1, const char *s2, const char *s3)
{
	if (s1)
	{
		ft_puterror(s1);
	}
	if (s2)
	{
		ft_puterror(": ");
		ft_puterror(s2);
		if (s3)
			ft_puterror(": ");
	}
	if (s3)
		ft_puterror(s3);
	ft_puterror("\n");
}
