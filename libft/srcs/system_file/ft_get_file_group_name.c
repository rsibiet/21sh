/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_group_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:09:37 by mressier          #+#    #+#             */
/*   Updated: 2016/02/25 12:09:38 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char		*ft_get_group_name(gid_t grp_id)
{
	struct group	*grp_info;
	char			*grp_name;

	grp_info = getgrgid(grp_id);
	if (grp_info == NULL || grp_info->gr_name == NULL)
		grp_name = ft_itoa(grp_id);
	else
		grp_name = ft_strdup(grp_info->gr_name);
	return (grp_name);
}
