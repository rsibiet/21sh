/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:41:43 by mressier          #+#    #+#             */
/*   Updated: 2016/02/25 14:41:44 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

enum e_file_mode		ft_get_file_mode(mode_t file_mode)
{
	if (S_ISREG(file_mode))
		return (REG_FILE);
	if (S_ISFIFO(file_mode))
		return (FIFO);
	if (S_ISCHR(file_mode))
		return (SPE_CHAR);
	if (S_ISDIR(file_mode))
		return (DIRECTORY);
	if (S_ISBLK(file_mode))
		return (SPE_BLK);
	if (S_ISSOCK(file_mode))
		return (SOCK_LINK);
	if (S_ISLNK(file_mode))
		return (SYM_LINK);
	else
		return (UNKNOW);
}
