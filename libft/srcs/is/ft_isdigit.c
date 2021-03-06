/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:05:00 by mressier          #+#    #+#             */
/*   Updated: 2016/03/31 17:21:16 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
