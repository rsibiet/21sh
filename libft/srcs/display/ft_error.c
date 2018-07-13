/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:24:23 by mressier          #+#    #+#             */
/*   Updated: 2016/05/09 15:24:24 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

/*
** mode : 0 = set error, 1 = get error, 10 = set str, 11 = get str
*/

static void			stock_error(int mode, char **str, enum e_error *error)
{
	static enum e_error		stck_error = NO_ERROR;
	static char				*stck_str = NULL;

	if (mode == 0 && error)
		stck_error = *error;
	else if (mode == 1 && error)
		*error = stck_error;
	else if (mode == 10 && str)
	{
		if (stck_str)
			ft_strdel(&stck_str);
		stck_str = *str;
	}
	else if (mode == 11)
		*str = (stck_str) ? stck_str : NULL;
}

enum e_error		get_error(void)
{
	enum e_error		error;

	stock_error(1, NULL, &error);
	return (error);
}

void				set_error(enum e_error error)
{
	stock_error(0, NULL, &error);
}

char				*get_str_error(void)
{
	char		*str_error;

	stock_error(11, &str_error, NULL);
	return (str_error);
}

void				set_str_error(char *str)
{
	char	*str_error;

	if (str)
		str_error = ft_strdup(str);
	else
		str_error = NULL;
	stock_error(10, &str_error, NULL);
}
