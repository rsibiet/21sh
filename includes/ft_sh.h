/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:32:03 by mressier          #+#    #+#             */
/*   Updated: 2016/06/02 14:28:54 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>

# include "../libft/includes/libz.h"
# include "define.h"

t_lst				*get_env(char **environ);

/*
** Create binary tree
*/
void				create_tree_and_launch(char **cmd, t_core **core);

/*
** Exit shell, as u can see
*/
void				exit_shell(int value, t_core **core);
void				reset_termcaps(void);

/*
** Initialisation
*/
int					init_termcaps(void);
int					init_shell(int ac, char **av);
t_lst				*init_env(char **environ);
t_core				*init_core(char **envp);
void				del_core(t_core **core);

/*
**  	------------------------------------------------------
**  	|						PARSER		         	     |
**  	------------------------------------------------------
*/

int					is_a_builtin_cmd(char *str);
int					is_a_complete_exec_cmd(char *str);
enum e_type_cmd		get_type_commande(char *cmd_line);
t_lst				*split_cmd_by_priority(char *cmd);
char				*parse_commande(char **cmd, t_lst *env);

/*
** replace
*/
char				*replace_all_tilde(char **cmd, t_lst *env);
char				*replace_all_dollar_var_by_env_var(char **cmd, t_lst *env);
char				*get_var_in_dollar_var(char *str, int i);

/*
**  	------------------------------------------------------
**  	|						EXEC_CMD	         	     |
**  	------------------------------------------------------
*/

int					handle_cmd(t_bin *branch, t_core *core);

/*
** exec_cmd_by_type
*/

int					exec_cmd_by_type(char **cmd, enum e_type_cmd type,
						t_core *core);

/*
** get cmd and argv
*/
char				**get_cmd_and_argv(char *str);

/*
** exec cmd with env path
*/
int					exec_cmd_with_env_paths(char **cmd, t_lst *env,
						t_lst *env_to_send);

/*
** exec builtin
*/
int					exec_built_in(char **cmd, t_core *core);

/*
** launch exec cmd
*/
int					launch_exec_cmd(const char *cmd, char **argv,
						t_lst *env);

/*
** exec_bin
*/
int					exec_bin_tree(t_bin *branch, t_core *core);

int					exec_pipe(t_bin *branch, t_core *core);
int					exec_semi_colons(t_bin *branch, t_core *core);
int					exec_redir(t_bin *branch, t_core *core);

/*
** heredoc
*/
void				heredoc(t_bin *branch, t_core *core);

/*
** get fd, redir flags
*/
int					get_fd(t_bin *branch, int flags);
int					get_redir(t_bin *branch);
int					get_redir_open_flags(int ope);

/*
**  	------------------------------------------------------
**  	|						BUILTIN		         	     |
**  	------------------------------------------------------
*/

/*
** tools
*/
enum e_builtin		get_type_builtin(char *built_cmd);

/*
** help
*/

void				disp_termcaps(void);
void				disp_syntax(void);
void				ft_help_builtin(void);

/*
** env
*/
t_lst				*ft_env_builtin(char **cmd, t_lst *env);
int					parse_flags_env(char **split_cmd, int *index, int **flag);

/*
** exit
*/
int					ft_exit_builtin(char **cmd);

/*
** setenv
*/
t_lst				*ft_setenv_builtin(char **cmd, t_lst *env);
int					set_env_with_param_values(char **split_cmd, t_lst **env,

						int *index, int *flags);

/*
** unsetenv
*/
t_lst				*ft_unsetenv_builtin(char **cmd, t_lst *env);

/*
** cd
*/
t_lst				*ft_cd_builtin(char **cmd, t_lst *env);
char				*parse_cd_dir(char *cmd, t_lst *env, int flag);
int					parse_cd_cmd_split(char **split_cmd, int *flags, int *i);
char				*cd_create_dir(const char *cmd, int flag, t_lst *env);
char				*cut_dir(char *cmd);
t_lst				*move_dir(char *cmd_dir, char *dir, t_lst *env, int flag);

/*
** Hashtable
*/
int					ft_builtin_hashtable(t_lst *env);
char				**malloc_hashtable(char **paths);
char				**get_hashtable(t_lst *env);
int					disp_hashtable(char **hashtable);
char				*hashtool(const char *str);

/*
** sort hashtable
*/
char				**sort_hashtable(char **htable);
int					cmp_values(char *str1,
						char *str2, int (*cmp)(long long int n1,
						long long int n2));
int					is_doublon(char **htable);
int					is_equal(long long int n1,
						long long int n2);

/*
** hashtable cmp
*/
int					is_inferior(long long int n1, long long int n2);
int					is_superior(long long int n1, long long int n2);
int					is_equal(long long int n1, long long int n2);
int					cmp_values(char *str1,
						char *str2, int (*cmp)(long long int n1,
						long long int n2));

/*
**  	------------------------------------------------------
**  	|						PATHS		         	     |
**  	------------------------------------------------------
*/

char				**get_valid_paths(t_lst *env);
int					is_a_valid_dir_path(char *str);

/*
**  	------------------------------------------------------
**  	|						SIGNAL		         	     |
**  	------------------------------------------------------
*/

void				ft_init_signal_handler_g(void);
void				ft_reset_signal_handler_g(void);
void				sig_handler_g(int sig);
void				ft_init_signal_handler_exec(void);
void				ft_reset_signal_handler_exec(void);
void				sig_handler_exec(int sig);
void				ft_init_sig_handler_heredoc(void);
void				ft_reset_sig_handler_heredoc(void);

/*
**  	------------------------------------------------------
**  	|						DISPLAY		         	     |
**  	------------------------------------------------------
*/

void				disp_help(void);
void				ft_pc(const char *color, const char *s);

/*
** error
*/
void				ft_puterror_twopart(const char *s1, const char *s2,
						const char *s3);
void				ft_error_few_arg(const char *cmd);
void				usage_error(char *str, char c);

/*
** prompt
*/
void				prompt(void);
int					get_len_prompt(void);
int					get_fd_prompt_sh(void);

/*
** env v opt
*/
void				prompt_opt_v_env(const char *action, const char *arg,
						char **av);

/*
**  	------------------------------------------------------
**  	|					BINARY TREE	 	        	     |
**  	------------------------------------------------------
*/

/*
** new bin
*/
t_bin				*new_t_bin(int ope, char *cmd);
t_bin				*add_t_bin(t_bin *branch, t_bin *left, t_bin *right);
t_bin				*add_t_bin_end_left(t_bin *branch, t_bin *to_add);
t_bin				*add_t_bin_end_right(t_bin *branch, t_bin *to_add);
t_bin				*modif_t_bin(t_bin *branch, int ope, char *str);

/*
** del bin
*/
void				del_one_t_bin(t_bin **del);
void				del_t_bin(t_bin *tree);
void				del_branch(t_bin *branch);

/*
** create tree
*/
t_bin				*create_tree(char *cmd);
t_bin				*tree_on_semi_colons(char *cmd);
t_bin				*tree_on_redir_and_pipe(t_bin *tree);

/*
** tree with cmp
*/
t_bin				*tree_with_cmp(t_bin *tree, int (*cmp)(int));
t_bin				*get_char_and_change_it(t_bin *branch, int (*cmp)(int));

/*
** Modif with operator
*/
t_bin				*modif_branch(t_bin *branch, int c);
t_bin				*pipe_modif(t_bin *branch);
t_bin				*semi_colons_modif(t_bin *branch);

/*
** redir modif
*/
t_bin				*redir_left_right_modif(t_bin *branch, int ope);
char				*get_output_name(char *str, int pos, int ope);

/*
** disp tree
*/
void				disp_tree(t_bin *tree);

/*
**  	------------------------------------------------------
**  	|						TOOLS		         	     |
**  	------------------------------------------------------
*/

int					is_exit_builtin(char *cmd);
int					is_separator(char c);
int					is_a_direct_path(const char *cmd);
int					is_quote(int c);

/*
** find operator in a str
*/
int					get_separator_char(char *str, int i);
int					str_cmp_separator_char(char *str, int (*cmp)(int));
int					str_find_separator_char(char *str, int (*cmp)(int));

/*
** find operator in tree
*/
int					is_an_ope_after(t_bin *branch, int ope);

/*
** is a redir char (| > < >> << >& <&)
*/
int					is_a_redir_pipe_char(int c);
int					is_a_redir_char(int c);
int					is_a_pipe_char(int c);
int					is_a_semi_colons(int c);
int					is_a_redir_et_char(int c);

void				ret_value_case(char *cmd, int ret);

/*
** Parsing tools
*/
char				*add_space_around_separator_char(char *cmd);

char				*sh_strintrim(const char *s);

char				**sh_strsplit(const char *s, char c);

/*
** get_new_cmd_without_redir
*/
char				*get_new_cmd_without_redir(char *str, int pos, int c);
int					get_end_cmd(char *str, int end);

/*
** delete quote
*/
char				*delete_quote(const char *str);

/*
** Hastable tools
*/
t_lst				*create_list_with_dir_content(DIR *dirp, const char *path);

/*
**  	------------------------------------------------------
**  	|						THREAD		         	     |
**  	------------------------------------------------------
*/

/*
** ft_fork.c
*/
int					ft_fork(void);
void				ft_end_fork(void);

/*
** ft_pipe.c
*/
int					ft_pipe(void);

#endif
