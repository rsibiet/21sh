/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_part_of_date.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:12:17 by mressier          #+#    #+#             */
/*   Updated: 2016/02/26 12:12:19 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

#define I_MONTH 4
#define LEN_DATE 7
#define I_HOURS 11
#define LEN_HOURS 5
#define I_YEARS 20
#define LEN_YEARS 4
#define NB_SECOND_IN_SIX_MONTH 15770000

static int		stc_date_oldest_than_six_month(time_t t)
{
	time_t		actual_time;

	actual_time = time(NULL);
	if (t <= (actual_time - NB_SECOND_IN_SIX_MONTH))
		return (1);
	return (0);
}

static char		*stc_get_part(const char *complete_date, time_t t)
{
	char		*ret_date;

	ret_date = ft_strsub(complete_date, I_MONTH, LEN_DATE);
	if (stc_date_oldest_than_six_month(t))
	{
		ret_date = ft_strfjoin(&ret_date, " ");
		ret_date = ft_strnfjoin(&ret_date, &complete_date[I_YEARS], LEN_YEARS);
	}
	else
		ret_date = ft_strnfjoin(&ret_date, &complete_date[I_HOURS], LEN_HOURS);
	return (ret_date);
}

/*
**  	------------------------------------------------------
**  	|						Main 		       	         |
**  	------------------------------------------------------
*/

char			*ft_interpret_date(time_t t)
{
	char	*complete_date;
	char	*ret_date;

	complete_date = ft_interpret_time(t);
	ret_date = stc_get_part(complete_date, t);
	return (ret_date);
}
