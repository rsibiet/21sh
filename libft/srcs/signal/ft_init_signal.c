/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 20:56:27 by mressier          #+#    #+#             */
/*   Updated: 2016/04/21 20:58:43 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void	ft_init_mult_sig(int *sig, int nb, void (*handler)(int))
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_init_signal(sig[i], handler);
		i++;
	}
}

void	ft_init_signal(int sig, void (*handler)(int))
{
	signal(sig, handler);
}
