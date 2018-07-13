/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 10:50:57 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/02 17:17:48 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include <unistd.h>

typedef struct dirent	t_dir;
typedef struct stat		t_stat;
typedef struct termios	t_term;

/*
** t_cmd: linked list of input before push entry
** t_link_cmd:
**		len = 	number of input
**		curse =	cursor position (between 0 & len)
**		c = number of column
**		size_hist = number of node of t_hist
**		pos = position first node to display
**		del_bt = position semicolon after first ( to del befor send cmd
**		del_be = position semicolon after first { to del befor send cmd
** t_cmd: stat: 0: normal
**				1: to copy
** quote[0] : '
** quote[1] : "
** quote[2] : `
** quote[3] : (
** quote[4] : [
** quote[5] : {
*/

typedef struct		s_cmd
{
	char			val;
	int				stat;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct		s_link_cmd
{
	char			*tmp;
	char			*search;
	int				quote[6];
	int				len;
	int				curse;
	int				pos;
	int				del_be;
	int				del_bt;
	int				c;
	t_cmd			*head;
	t_cmd			*tail;
}					t_link_cmd;

typedef struct		s_hist
{
	char			*s;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

typedef struct		s_link_hist
{
	char			*tp;
	char			c[4];
	int				pos_n;
	int				size_hist;
	int				sig_cl;
	int				sig_int;
	char			*copy;
	t_hist			*head;
	t_hist			*tail;
	t_hist			*cur;
}					t_link_hist;

/*
** Init
*/
t_link_hist			init_link_hist(t_hist *hist);

/*
** fonctions in save_history file
*/

t_link_hist			*ft_save_lh(t_link_hist *lh, int i);
t_link_cmd			*ft_save_cmd(t_link_cmd *cmd, int i);

/*
** fonctions in termcaps_21sh file
*/

char				*termcaps_21sh(t_link_hist *lh);

/*
** fonctions in termcaps_21sh2 file
*/

char				*put_command(t_link_cmd *ln, int i, char *s, t_cmd *cmd);
void				update_historique(t_hist *hist, t_link_hist *lh, char *s,
			t_hist *new);
/*
** init termcaps
*/

t_link_cmd			init_cmd(t_cmd *cmd);

/*
** fonctions in command_21sh file
*/

void				ft_cmd_del(t_cmd *lst);
void				ft_cmd_delone(t_cmd **lst, t_cmd *node);
t_cmd				*ft_cmdnew(void);
void				push_back_cmd(t_link_cmd *ln, t_cmd *new);

/*
** fonctions in move_cursor file
*/

int					ft_isbackslash_n(t_cmd *cmd, t_link_cmd *ln, int i);
int					get_len_curpr(int i, t_link_cmd *ln);
void				move_right(t_link_cmd *ln, int i);
void				move_cursor(t_link_cmd *ln, char c[3], t_hist **hist,
						t_link_hist *lh);

/*
** fonctions in nav_history file
*/

void				up_historique(t_link_cmd *ln, t_cmd *new, t_hist **hist,
						t_link_hist *lh);
void				down_historique(t_link_cmd *ln, t_cmd *new, t_hist **hist,
						t_link_hist *lh);

/*
** fonctions in historique_21sh file
*/

void				ft_hist_del(t_hist *lst);
void				ft_hist_delone(t_hist **lst, t_hist *node);
t_hist				*ft_histnew(void);
void				push_back_lst(t_link_hist *ln, t_hist *new);

/*
** fonctions in copy_cut file
*/

void				copy_cut_stick(char c[3], t_link_cmd *ln, int tp,
						t_link_hist *lh);
/*
** fonctions in move_cursor_3 file
*/

void				move_by_word(t_link_cmd *ln, char c, int i,
						t_cmd *cmd);
void				display_cut_part(t_cmd *cmd, t_link_cmd *ln, int i);

/*
** fonctions in home_end_key file
*/

void				home_end_key(t_link_cmd *ln, char c, t_cmd *cmd, int i);
void				ctrl_up_down(int pr, char c, t_link_cmd *ln, int nb);

/*
** fonctions in delete_cmd file
*/

void				ft_delete_command(t_link_cmd *ln, int i);

/*
** fonctions in insert_char file
*/

void				insert_in_quote(t_cmd *cmd, int tp, int i, t_link_cmd *ln);
void				insert_char(t_cmd *cmd, t_link_cmd *ln, char c, int i);

/*
** fonctions in research_in_hist file
*/

void				clear_cmd(t_link_cmd *ln, t_cmd *cmd);
int					ctrl_r_21sh2(t_link_cmd *ln, int i, char c[3]);
void				ctrl_r_21sh(t_link_cmd *ln, int i, t_link_hist *lh);

/*
** fonctions in research_in_hist2 file
*/

void				ct_rx();

/*
** fonctions in autocompletion file
*/

int					autocompletion(t_link_cmd *ln, t_cmd *cmd, t_link_hist *lh);

/*
** fonctions in quotes_21sh file
*/

int					quotes_21sh(t_link_cmd *ln, t_cmd *cmd);

/*
** fonctions in quotes_21sh2 file
*/

void				add_backslash_n(t_link_cmd *ln, t_cmd *new_cmd);
void				quotes_21sh2(t_link_cmd *ln, t_link_hist *lh, char *s);
void				memorize_cmd(t_link_cmd *ln, t_cmd *cmd, int i);

/*
** fonctions in brackets file
*/

void				bracket_hook_brace(t_link_cmd *ln, int bt, int be, int tp);

/*
** fonctions in brackets2 file
*/

int					control_double_brace(t_cmd *cmd, int pos, int i);
int					control_cmd(t_cmd *cmd, t_link_cmd *ln, int i, int nb);
void				add_semicolon(t_link_cmd *ln, t_cmd *new, int i);

/*
** fonctions in del_cmd_hist file
*/

void				del_cmd_hist(t_link_cmd *ln, t_cmd *cnd, int nb, int i);

/*
** fonctions in copy_cut2 file
*/

int					last_backslash_n(t_cmd *cmd, int nb);

/*
** fonctions in disp_cut_part file
*/

void				display_copy_part(t_link_cmd *ln, int nb, int i);

/*
** fonctions in ctrl_d_21sh file
*/

void				insert_cmd_tmp(t_link_hist *lh, t_link_cmd *ln, int i);
void				put_command_in_tp(t_link_cmd *ln, t_cmd *cmd,
						t_link_hist *lh, int i);
int					ctrl_d(t_link_cmd *ln, t_link_hist *lh);

/*
** putchar int
*/

int					ft_putchar_int(int c);
void				ft_putstr_intfd(char *str);
void				ft_putstr_color_intfd(const char *color, const char *str);

/*
** fonctions in clear_screen file
*/

void				clear_screen_sh(t_link_cmd *ln, t_cmd *cmd, int i);

/*
** fonctions in stick_ext file
*/

void				stick_ext(t_cmd *cmd, t_link_cmd *ln, char c, int i);

#endif
