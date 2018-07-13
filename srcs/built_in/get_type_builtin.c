/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 13:29:19 by mressier          #+#    #+#             */
/*   Updated: 2016/05/09 13:29:21 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

enum e_builtin			get_type_builtin(char *built_cmd)
{
	if (ft_strequ(built_cmd, ENV))
		return (BT_ENV);
	if (ft_strequ(built_cmd, SETENV))
		return (BT_SETENV);
	if (ft_strequ(built_cmd, UNSETENV))
		return (BT_UNSETENV);
	if (ft_strequ(built_cmd, CD))
		return (BT_CD);
	if (ft_strequ(built_cmd, HASHTABLE))
		return (BT_HASHTABLE);
	if (ft_strequ(built_cmd, EXIT) || ft_strequ(built_cmd, HELP))
		return (BT_OTHER);
	return (BT_UNKNOW);
}
