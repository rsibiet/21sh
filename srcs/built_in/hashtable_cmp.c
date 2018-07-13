/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:26:08 by mressier          #+#    #+#             */
/*   Updated: 2016/05/25 17:26:09 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int					is_inferior(long long int n1, long long int n2)
{
	if (n1 < n2)
		return (1);
	return (0);
}

int					is_superior(long long int n1, long long int n2)
{
	if (n1 > n2)
		return (1);
	return (0);
}

int					is_equal(long long int n1, long long int n2)
{
	if (n1 == n2)
		return (1);
	return (0);
}

int					cmp_values(char *str1,
						char *str2, int (*cmp)(long long int n1,
						long long int n2))
{
	char			**split_s1;
	char			**split_s2;
	int				ret;

	ret = 1;
	split_s1 = ft_strsplit_once(str1, ' ');
	split_s2 = ft_strsplit_once(str2, ' ');
	if (cmp(ft_atolli(split_s1[0]), ft_atolli(split_s2[0])) == 0)
		ret = 0;
	ft_str_tab_del(&split_s1);
	ft_str_tab_del(&split_s2);
	return (ret);
}
