/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:41:51 by mressier          #+#    #+#             */
/*   Updated: 2016/02/25 17:41:52 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

static char		*stc_get_others_rights(mode_t file_mode)
{
	char	*rights;

	rights = ft_strdup("---");
	if (file_mode & S_IROTH)
		rights[0] = 'r';
	if (file_mode & S_IWOTH)
		rights[1] = 'w';
	if (file_mode & S_IXOTH)
		rights[2] = (file_mode & S_ISVTX) ? 't' : 'x';
	else if (file_mode & S_ISVTX)
		rights[2] = 'T';
	return (rights);
}

static char		*stc_get_grp_right(mode_t file_mode)
{
	char	*rights;

	rights = ft_strdup("---");
	if (file_mode & S_IRGRP)
		rights[0] = 'r';
	if (file_mode & S_IWGRP)
		rights[1] = 'w';
	if (file_mode & S_IXGRP)
		rights[2] = (file_mode & S_ISGID) ? 's' : 'x';
	else if (file_mode & S_ISGID)
		rights[2] = 'S';
	return (rights);
}

static char		*stc_get_owner_right(mode_t file_mode)
{
	char	*rights;

	rights = ft_strdup("---");
	if (file_mode & S_IRUSR)
		rights[0] = 'r';
	if (file_mode & S_IWUSR)
		rights[1] = 'w';
	if (file_mode & S_IXUSR)
		rights[2] = (file_mode & S_ISUID) ? 's' : 'x';
	else if (file_mode & S_ISUID)
		rights[2] = 'S';
	return (rights);
}

char			*ft_get_file_right(mode_t file_mode)
{
	char	*file_rights;
	char	*owner_rights;
	char	*grp_rights;
	char	*oth_rights;
	char	*tmp;

	owner_rights = stc_get_owner_right(file_mode);
	grp_rights = stc_get_grp_right(file_mode);
	oth_rights = stc_get_others_rights(file_mode);
	tmp = ft_strfjoin(&grp_rights, oth_rights);
	file_rights = ft_strfjoin(&owner_rights, tmp);
	ft_strdel(&tmp);
	ft_strdel(&oth_rights);
	return (file_rights);
}
