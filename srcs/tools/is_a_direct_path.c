/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_direct_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:25:31 by mressier          #+#    #+#             */
/*   Updated: 2016/05/11 11:25:34 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					is_a_direct_path(const char *cmd)
{
	if (ft_strlen(cmd) >= 2 && ft_strnequ(cmd, "./", 2))
		return (1);
	if (ft_strlen(cmd) >= 3 && ft_strnequ(cmd, "../", 3))
		return (1);
	if (cmd[0] == '/')
		return (1);
	return (0);
}
