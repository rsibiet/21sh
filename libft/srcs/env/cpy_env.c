/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:40:15 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 16:40:17 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

t_lst				*cpy_env(t_lst *env)
{
	char	**stock_env;
	t_lst	*new_env;

	stock_env = create_str_env(env);
	new_env = create_lst_env_from_environ_var(stock_env);
	ft_str_tab_del(&stock_env);
	return (new_env);
}
