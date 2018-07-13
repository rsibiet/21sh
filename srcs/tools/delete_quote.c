/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 19:38:18 by mressier          #+#    #+#             */
/*   Updated: 2016/05/21 19:38:19 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char		*modif_quote(int *qt, char **new, int *i)
{
	char		*tmp;

	if (*qt == 0 || *qt == (*new)[*i])
	{
		*qt = (*qt == 0 ? (*new)[*i] : 0);
		if ((*new)[*i] != BCKQUOTE)
		{
			tmp = ft_cut_str(*new, *i, *i);
			ft_strdel(new);
			*new = tmp;
			(*i)--;
		}
	}
	return (*new);
}

char			*delete_quote(const char *str)
{
	char		*new;
	int			qt;
	int			i;

	i = 0;
	qt = 0;
	new = ft_strdup(str);
	while (new[i])
	{
		if (is_quote(new[i]))
			new = modif_quote(&qt, &new, &i);
		i++;
	}
	return (new);
}
