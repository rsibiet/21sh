/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:05:59 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 11:06:00 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					ft_exit_builtin(char **cmd)
{
	unsigned char	value;

	value = -1;
	if (ft_strequ(cmd[0], EXIT) && ft_str_array_len(cmd) == 1)
		return (0);
	if (ft_str_is_digit(cmd[1]) && ft_str_array_len(cmd) == 2)
		value = ft_atoi(cmd[1]);
	else
	{
		if (ft_str_array_len(cmd) > 2)
			set_perror(NULL, TOO_MANY_ARG);
		else
			set_perror(NULL, EXPR_SYNTAX);
		ft_perror(EXIT);
		return (-1);
	}
	return (value);
}
