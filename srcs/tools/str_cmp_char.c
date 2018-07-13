/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 14:37:54 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 10:06:47 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					is_an_ope_after(t_bin *branch, int ope)
{
	t_bin			*cur;

	cur = branch;
	while (cur)
	{
		if (cur->ope == ope)
			return (1);
		cur = cur->left;
	}
	return (0);
}

int					str_cmp_separator_char(char *str, int (*cmp)(int))
{
	int			i;
	int			c;

	i = str_find_separator_char(str, cmp);
	if (i == -1)
		return (-1);
	c = get_separator_char(str, i);
	return (c);
}

int					str_find_separator_char(char *str, int (*cmp)(int))
{
	int		i;
	int		count;
	int		c;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
		{
			if (count == 0)
				count = str[i];
			else if (count == str[i])
				count = 0;
		}
		c = get_separator_char(str, i);
		if (count == 0 && cmp(c))
			return (i);
		i++;
	}
	return (-1);
}
