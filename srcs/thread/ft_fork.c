/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:13:01 by mressier          #+#    #+#             */
/*   Updated: 2016/05/12 14:13:02 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					ft_fork(void)
{
	int		pid;

	pid = 0;
	ft_reset_signal_handler_g();
	ft_init_signal_handler_exec();
	pid = fork();
	return (pid);
}

void				ft_end_fork(void)
{
	ft_reset_signal_handler_exec();
	ft_init_signal_handler_g();
}
