/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ_caseins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:32:06 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 17:32:07 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int		ft_strequ_caseins(const char *s1, const char *s2)
{
	char	*cp_s1;
	char	*cp_s2;
	int		res;

	cp_s1 = ft_str_toupper(ft_strdup(s1));
	cp_s2 = ft_str_toupper(ft_strdup(s2));
	res = ft_strequ(cp_s1, cp_s2);
	ft_strdel(&cp_s1);
	ft_strdel(&cp_s2);
	return (res);
}
