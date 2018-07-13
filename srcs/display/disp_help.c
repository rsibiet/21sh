/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_cool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:47:27 by mressier          #+#    #+#             */
/*   Updated: 2016/06/02 14:19:13 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

void			ft_pc(const char *color, const char *s)
{
	ft_putstr_color(color, s);
}

void			disp_help(void)
{
	ft_pc(C_G_RED,
		"\t\t    ,---.  ,--.       ,--. \n");
	ft_pc(C_G_YELLOW,
		"\t\t   '.-.  \\/   | ,---. |  ,---. \n");
	ft_pc(C_G_GREEN,
		"\t\t    .-' .'`|  |(  .-' |  .-.  | \n");
	ft_pc(C_G_BLUE,
		"\t\t   /   '-. |  |.-'  `)|  | |  | \n");
	ft_pc(C_G_PURPLE,
		"\t\t   '-----' `--'`----' `--' `--' \n");
}
