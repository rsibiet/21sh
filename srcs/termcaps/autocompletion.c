/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:20:32 by rsibiet           #+#    #+#             */
/*   Updated: 2016/05/14 14:33:03 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "ft_sh.h"
#include <dirent.h>

static void		search_in_doc(DIR *rep, int i, char *tmp, t_link_cmd *ln)
{
	t_dir	*file;

	while ((file = readdir(rep)) != NULL)
	{
		i = 0;
		while (file->d_name[i] != '\0' && file->d_name[i] == tmp[i])
			i++;
		if (tmp[i] == '\0')
		{
			while (file->d_name[i] != '\0')
				insert_char(ln->head, ln, file->d_name[i++], 0);
			return ;
		}
	}
}

static void		select_last_word(t_link_cmd *ln, char *tmp2, int i, int j)
{
	while (i > 0 && ln->tmp[i] != ' ')
		i--;
	if (i != 0)
	{
		tmp2 = ft_strsub(ln->tmp, i + 1, j - i);
		if (ln->tmp[0] != '\0')
		{
			ft_strdel(&ln->tmp);
			ln->tmp = tmp2;
		}
	}
}

int				autocompletion(t_link_cmd *ln, t_cmd *cmd, t_link_hist *lh)
{
	DIR		*rep;

	if (ln->curse == ln->len && ln->tail->prev->val == ' ')
	{
		put_command_in_tp(ln, ln->head, lh, 0);
		return (1);
	}
	memorize_cmd(ln, ln->head, 0);
	if ((rep = opendir(".")) == NULL)
		return (0);
	select_last_word(ln, NULL, ft_strlen(ln->tmp), ft_strlen(ln->tmp));
	if (ln->tmp[0] != '\0')
		search_in_doc(rep, 0, ln->tmp, ln);
	if (closedir(rep) == -1)
	{
		ft_puterror("closing of directory '.' failed.");
		exit_shell(1, NULL);
	}
	if (ln && cmd)
		cmd = ln->head;
	return (0);
}
