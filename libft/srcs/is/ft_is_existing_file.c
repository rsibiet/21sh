/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_existing_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 17:06:53 by mressier          #+#    #+#             */
/*   Updated: 2016/04/21 17:06:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int		ft_is_existing_file(const char *pathname)
{
	struct stat		ret_stat;

	if (stat(pathname, &ret_stat) == -1)
		return (0);
	return (1);
}
