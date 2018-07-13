/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:25:08 by mressier          #+#    #+#             */
/*   Updated: 2016/03/29 14:13:15 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYSTEM_H
# define FT_SYSTEM_H

# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <time.h>

# include "libz.h"

enum					e_file_mode
{
	FIFO = 0,
	SPE_CHAR,
	SPE_BLK,
	DIRECTORY,
	SYM_LINK,
	SOCK_LINK,
	REG_FILE,
	UNKNOW
};

/*
**  	------------------------------------------------------
**  	|					Get file info        	         |
**  	------------------------------------------------------
*/

char					*ft_get_owner_name(uid_t uid);
char					*ft_get_group_name(gid_t grp_id);
char					*ft_get_file_right(mode_t file_mode);
enum e_file_mode		ft_get_file_mode(mode_t file_mode);
int						*ft_get_maj_and_min_dev(dev_t dev_id);

/*
**  	------------------------------------------------------
**  	|						Date 		       	         |
**  	------------------------------------------------------
*/

char					*ft_interpret_time(time_t value_time);
char					*ft_interpret_date(time_t t);

#endif
