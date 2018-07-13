/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_strintrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:05:02 by mressier          #+#    #+#             */
/*   Updated: 2016/05/18 11:05:04 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "libz.h"

char			*sh_strintrim(const char *s)
{
	char	*tmp_s;
	char	*new;
	char	**split;

	tmp_s = ft_strtrim(s);
	split = sh_strsplit(tmp_s, ' ');
	new = ft_implode(split, ' ');
	ft_str_tab_del(&split);
	ft_strdel(&tmp_s);
	return (new);
}
