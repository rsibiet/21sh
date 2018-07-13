/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_complete_exec_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:46:09 by mressier          #+#    #+#             */
/*   Updated: 2016/04/25 17:46:11 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					is_a_complete_exec_cmd(char *str)
{
	int		ret;

	ret = 0;
	if (ft_is_exec_file(str))
		ret = 1;
	return (ret);
}
