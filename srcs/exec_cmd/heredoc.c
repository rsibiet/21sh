/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:42:40 by mressier          #+#    #+#             */
/*   Updated: 2016/05/30 14:51:00 by tomo-chan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "termcaps.h"

static int			ft_put(void)
{
	ft_putstr_intfd("heredoc> ");
	return (1);
}

static t_lst		*get_stock(char *end)
{
	t_lst		*stock;
	char		*line;

	stock = NULL;
	line = NULL;
	end = ft_strtrim(end);
	ft_save_lh(NULL, 1)->sig_cl = 2;
	ft_reset_signal_handler_g();
	ft_init_sig_handler_heredoc();
	while (ft_put())
	{
		line = termcaps_21sh(ft_save_lh(NULL, 1));
		if (line == NULL || ft_strequ(line, end))
			break ;
		else
			stock = ft_lst_add_end(ft_lst_new(line), stock);
	}
	ft_reset_sig_handler_heredoc();
	ft_init_signal_handler_g();
	ft_save_lh(NULL, 1)->sig_cl = 0;
	ft_strdel(&line);
	ft_strdel(&end);
	return (stock);
}

static void			put_stock(t_lst *stock, char *str_fd)
{
	t_lst		*cur;
	int			fd;

	cur = stock;
	fd = (*str_fd ? ft_atoi(str_fd) : STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	while (cur)
	{
		ft_putendl((char *)cur->data);
		cur = cur->next;
	}
	ft_lst_del(&stock, (void (*)(void **))ft_strdel);
	exit(0);
}

void				heredoc(t_bin *branch, t_core *core)
{
	t_lst			*stock;
	char			**split_fd;
	int				pid;

	split_fd = ft_strsplit_once(branch->right->cmd, ' ');
	pid = ft_pipe();
	if (pid == -1)
		return ;
	if (pid == CHILD)
	{
		stock = get_stock(split_fd[1]);
		put_stock(stock, split_fd[0]);
		exit(0);
	}
	ft_str_tab_del(&split_fd);
	wait(NULL);
	exec_bin_tree(branch->left, core);
	ft_end_fork();
	exit(0);
}
