/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_owner_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:28:26 by mressier          #+#    #+#             */
/*   Updated: 2016/02/23 18:28:28 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

char		*ft_get_owner_name(uid_t usr_id)
{
	struct passwd	*usr_info;
	char			*usr_name;

	usr_info = getpwuid(usr_id);
	if (usr_info == NULL || usr_info->pw_name == NULL)
		usr_name = ft_itoa(usr_id);
	else
		usr_name = ft_strdup(usr_info->pw_name);
	return (usr_name);
}
