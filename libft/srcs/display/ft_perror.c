/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:23:50 by mressier          #+#    #+#             */
/*   Updated: 2016/05/09 15:23:52 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void				ft_put_error_message(enum e_error error)
{
	char		**str;

	str = get_all_messages();
	if (error <= NB_ERROR && str[error])
		ft_puterror(str[error]);
	ft_str_tab_del(&str);
}

static void			ft_put_error(void)
{
	char				*str;
	char				*tmp;
	enum e_error		error;

	str = NULL;
	tmp = get_str_error();
	if (tmp)
		str = ft_strdup(tmp);
	error = get_error();
	ft_put_error_message(error);
	if (str)
	{
		while (ft_strchr(str, '\n'))
		{
			ft_str_replace_str(&str,
				ft_search_and_replace_char(str, "\\n", '\n'));
		}
		ft_puterror(": ");
		ft_puterror(str);
	}
	ft_strdel(&str);
	ft_puterror("\n");
}

void				ft_perror(const char *str)
{
	if (str && str[0])
	{
		ft_puterror(str);
		ft_puterror(": ");
	}
	ft_put_error();
}
