/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_in_dollar_var.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 10:43:43 by mressier          #+#    #+#             */
/*   Updated: 2016/05/26 10:43:45 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int			is_a_dollar_var(char *str, int i)
{
	if (str[i] && str[i] == '$' && str[i + 1] && str[i + 1] != '$'
			&& ((i - 1 >= 0 && str[i - 1] != '$') || (i - 1 < 0)))
		return (1);
	return (0);
}

char				*get_var_in_dollar_var(char *str, int i)
{
	char		*var;
	int			n;
	int			len;

	if (is_a_dollar_var(str, i) == 0)
		return (NULL);
	n = i + 1;
	while (str[n] && ft_isalnum(str[n]))
		n++;
	len = n - i;
	var = ft_strsub(str, i, len);
	return (var);
}
