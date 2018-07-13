/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terminal_dimensions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 14:27:41 by mressier          #+#    #+#             */
/*   Updated: 2016/03/06 14:27:42 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

int		*get_terminal_dimensions(void)
{
	int		*term_dim;

	term_dim = (int *)ft_memalloc(sizeof(int) * 2);
	term_dim[0] = get_terminal_nb_line();
	term_dim[1] = get_terminal_nb_col();
	return (term_dim);
}
