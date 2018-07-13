/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_commande.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:47:56 by mressier          #+#    #+#             */
/*   Updated: 2016/04/25 17:47:58 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

enum e_type_cmd		get_type_commande(char *cmd)
{
	if (!cmd || !cmd[0])
		return (NOTHING);
	else if (is_a_builtin_cmd(cmd))
		return (BUILT_IN);
	else
		return (OTHER);
}
