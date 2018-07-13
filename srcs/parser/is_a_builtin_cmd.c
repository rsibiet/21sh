/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:45:52 by mressier          #+#    #+#             */
/*   Updated: 2016/04/25 17:45:55 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					is_a_builtin_cmd(char *str)
{
	enum e_builtin	type;
	int				ret;

	ret = 0;
	type = get_type_builtin(str);
	if (type != BT_UNKNOW)
		ret = 1;
	return (ret);
}
