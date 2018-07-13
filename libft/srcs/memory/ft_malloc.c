/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:14:25 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:07:48 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Make a malloc. If it not success, put an error and exit the prog
*/

#include "libz.h"

void	*ft_malloc(size_t size)
{
	void	*mem;

	mem = (unsigned char *)malloc(size);
	if (mem == NULL)
	{
		ft_puterror("Allocation failed");
		exit(1);
	}
	return (mem);
}
