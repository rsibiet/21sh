/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 18:52:06 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 18:52:07 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char				*ft_get_pwd(void)
{
	char	*pwd;
	int		len;

	len = 256;
	pwd = ft_strnew(len);
	while (getcwd(pwd, len) == NULL)
	{
		ft_strdel(&pwd);
		len *= 2;
		if (len > 2000)
			return (ft_strdup("."));
		pwd = ft_strnew(len);
	}
	return (pwd);
}
