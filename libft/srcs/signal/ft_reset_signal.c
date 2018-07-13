/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 21:09:09 by mressier          #+#    #+#             */
/*   Updated: 2016/04/21 21:09:11 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void			ft_reset_mult_sig(int *sig, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_reset_signal(sig[i]);
		i++;
	}
}

void			ft_reset_signal(int sig)
{
	ft_init_signal(sig, SIG_DFL);
}
