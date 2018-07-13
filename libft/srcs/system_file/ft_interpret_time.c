/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret_date.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:52:06 by mressier          #+#    #+#             */
/*   Updated: 2016/02/26 11:52:07 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

/*
**	returns a pointer to a 26-character string of the form:
**           Thu Nov 24 18:22:48 1986\n\0
*/

char		*ft_interpret_time(time_t value_time)
{
	char	*date;

	date = ctime(&value_time);
	return (date);
}
