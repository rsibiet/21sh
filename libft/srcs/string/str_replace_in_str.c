/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace_in_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 11:28:07 by mressier          #+#    #+#             */
/*   Updated: 2016/05/26 11:28:09 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char		*ft_str_replace_in_str(const char *str, const char *to_rep,
					const char *new, int i)
{
	char	**split_tmp;
	char	*tmp;
	char	*new_cmd;

	split_tmp = ft_strsplit_index(str, i);
	tmp = ft_cut_str(split_tmp[1], 0, ft_strlen(to_rep) - 1);
	new_cmd = ft_strjoin(split_tmp[0], new);
	new_cmd = ft_strfjoin(&new_cmd, tmp);
	ft_strdel(&tmp);
	ft_str_tab_del(&split_tmp);
	return (new_cmd);
}
