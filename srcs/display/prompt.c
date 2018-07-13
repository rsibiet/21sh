/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:36:28 by mressier          #+#    #+#             */
/*   Updated: 2016/04/26 12:36:29 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "termcaps.h"
#include <term.h>

static void			do_prompt(const char *user, const char *pwd,
						const char *host)
{
	if (user)
		ft_putstr_color_intfd(C_G_PURPLE, user);
	else
		ft_putstr_color_intfd(C_G_PURPLE, DEF_USR);
	if (host)
	{
		ft_putstr_color_intfd(C_G_YELLOW, "(");
		ft_putstr_color_intfd(C_G_YELLOW, host);
		ft_putstr_color_intfd(C_G_YELLOW, ")");
	}
	if (ft_strrchr(pwd, '/'))
	{
		if (pwd[0] == '/' && ft_count_char(pwd, '/') == 1)
			;
		else
			pwd = ft_strrchr(pwd, '/') + 1;
	}
	if (pwd)
		ft_putstr_color_intfd(C_G_GREEN, pwd);
	ft_putstr_color_intfd(C_G_CYAN, " ►  ");
}

static int			get_len(const char *user, const char *pwd,
						const char *host)
{
	int				n;

	n = 0;
	if (user)
		n += ft_strlen(user);
	else
		n += ft_strlen(DEF_USR);
	if (host)
		n += ft_strlen(host) + 2;
	if (ft_strrchr(pwd, '/'))
	{
		if (pwd[0] == '/' && ft_count_char(pwd, '/') == 1)
			;
		else
			pwd = ft_strrchr(pwd, '/') + 1;
	}
	if (pwd)
		n += ft_strlen(pwd);
	n += 4;
	return (n);
}

int					get_len_prompt(void)
{
	char	*user;
	char	*pwd;
	char	*host;
	int		len;

	pwd = ft_get_pwd();
	host = ft_get_host_name();
	user = getenv("USER");
	len = get_len(user, pwd, host);
	ft_strdel(&pwd);
	ft_strdel(&host);
	return (len);
}

void				prompt(void)
{
	char	*user;
	char	*pwd;
	char	*host;

	pwd = ft_get_pwd();
	host = ft_get_host_name();
	user = getenv("USER");
	do_prompt(user, pwd, host);
	ft_strdel(&pwd);
	ft_strdel(&host);
}
