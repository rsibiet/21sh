/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:38:06 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:14:02 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new string full of 0 with a \0 final
*/

#include "libz.h"

char	*ft_strnew(size_t size)
{
	return (ft_memalloc(sizeof(char) * (size + 1)));
}
