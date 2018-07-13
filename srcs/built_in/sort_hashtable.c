/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hashtable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 19:41:46 by mressier          #+#    #+#             */
/*   Updated: 2016/05/24 19:41:47 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int			stc_ft_sort(char **htable, int right, int left, char *n)
{
	char		*tmp;

	while (1)
	{
		while (cmp_values(htable[right], n, is_superior))
			right--;
		while (cmp_values(htable[left], n, is_inferior))
			left++;
		if (left < right)
		{
			tmp = htable[right];
			htable[right] = htable[left];
			htable[left] = tmp;
			right--;
			left++;
		}
		else
			break ;
	}
	return (right);
}

static void			quick_sort(char **htable, int start, int end)
{
	int			left;
	int			right;
	char		*n;

	left = start;
	right = end;
	if (start >= end)
		return ;
	n = ft_strdup(htable[start]);
	right = stc_ft_sort(htable, right, left, n);
	ft_strdel(&n);
	quick_sort(htable, start, right);
	quick_sort(htable, right + 1, end);
}

char				**sort_hashtable(char **htable)
{
	if (htable && htable[0])
		quick_sort(htable, 0, ft_str_array_len(htable) - 1);
	return (htable);
}
