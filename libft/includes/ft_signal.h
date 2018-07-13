/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 20:57:22 by mressier          #+#    #+#             */
/*   Updated: 2016/04/21 20:58:29 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

# include <signal.h>

void			ft_init_mult_sig(int *sig, int nb, void (*handler)(int));
void			ft_reset_mult_sig(int *sig, int nb);
void			ft_init_signal(int sig, void (*handler)(int));
void			ft_reset_signal(int sig);

#endif
