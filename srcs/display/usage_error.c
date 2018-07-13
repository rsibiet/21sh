/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:28:22 by mressier          #+#    #+#             */
/*   Updated: 2016/04/27 14:28:23 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void		cd_usage_error(void)
{
	ft_puterror("cd [-PL][-|<dir>]");
}

static void		env_usage_error(void)
{
	ft_puterror("env [iv] [name=value] \n\t[utility [arg ...]]");
}

void			usage_error(char *str, char c)
{
	ft_putstr(str);
	ft_putstr(": illegal option -- ");
	ft_putchar(c);
	ft_puterror("\nUsage : ");
	if (ft_strequ(str, CD))
		cd_usage_error();
	else if (ft_strequ(str, ENV))
		env_usage_error();
	ft_putstr(".\n");
}
