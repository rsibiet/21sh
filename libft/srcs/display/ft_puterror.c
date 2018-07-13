/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:57:53 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:19:39 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Print a str in the Standard Error
*/

#include "libz.h"

void	ft_puterror(const char *str)
{
	ft_putstr_fd(str, 2);
}
