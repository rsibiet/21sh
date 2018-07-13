/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:39:35 by mressier          #+#    #+#             */
/*   Updated: 2016/04/25 18:39:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

void			ft_disp_env(t_lst *env)
{
	t_lst	*cur;

	cur = env;
	while (cur)
	{
		ft_putstr(((char *)((t_env *)cur->data)->name));
		ft_putchar('=');
		ft_putendl(((char *)((t_env *)cur->data)->content));
		cur = cur->next;
	}
}
