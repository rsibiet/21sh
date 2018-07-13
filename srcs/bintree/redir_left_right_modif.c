/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_left_right_modif.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:20:47 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 15:48:04 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_bin		*modif_branch_with_new_cmd(char *output, char *new_cmd,
							t_bin *branch, int ope)
{
	if (output && output[0] && new_cmd)
	{
		branch = modif_t_bin(branch, ope, NULL);
		branch = add_t_bin(branch, new_t_bin(0, new_cmd), new_t_bin(0, output));
	}
	else
	{
		if (new_cmd == NULL)
			set_perror(NULL, NULL_CMD);
		branch = NULL;
	}
	return (branch);
}

static char			*get_new_cmd(char *str, int ope, char *output, int index)
{
	char			*new;
	int				i;

	new = get_new_cmd_without_redir(str, index, ope);
	if (output && output[0] != ' ')
	{
		if (ope == DB_REDIR_LEFT || ope == DB_REDIR_RIGHT)
			index--;
		i = index - 1;
		while (i >= 0 && new[i] != output[0])
			i--;
		if (i >= 0)
		{
			ft_str_replace_str(&new, ft_cut_str(new, i, index - 1));
			ft_str_replace_str(&new, sh_strintrim(new));
		}
		else
			ft_str_replace_str(&new, ft_strdup(""));
	}
	return (new);
}

t_bin				*redir_left_right_modif(t_bin *branch, int ope)
{
	char	*new_cmd;
	char	*output;
	int		pos;

	pos = str_find_separator_char(branch->cmd, is_a_redir_char);
	output = get_output_name(branch->cmd, pos, ope);
	new_cmd = get_new_cmd(branch->cmd, ope, output, pos);
	branch = modif_branch_with_new_cmd(output, new_cmd, branch, ope);
	ft_strdel(&output);
	ft_strdel(&new_cmd);
	return (branch);
}
