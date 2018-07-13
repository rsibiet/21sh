/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:43:49 by mressier          #+#    #+#             */
/*   Updated: 2016/04/20 12:43:50 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_ENV_H
# define SHELL_ENV_H

# include "libz.h"

# define BASIC_PATH "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin"

typedef struct		s_env
{
	char			*name;
	char			*content;
}					t_env;

/*
** Create elem
*/
t_env				*create_env_elem_by_split(char *str);
t_env				*create_env_elem(const char *name, const char *content);

/*
** Create list or char **
*/
char				**create_str_env(t_lst *env);
t_lst				*create_basic_lst_env(void);
t_lst				*create_lst_env_from_environ_var(char **environ);
t_lst				*cpy_env(t_lst *env);

/*
** Add, modifiy
*/
t_lst				*modif_env_elem(t_lst *list,
						const char *name, const char *content);
t_lst				*add_env_elem(t_lst *list,
						const char *name, const char *content);
t_lst				*add_or_modif_env_elem(t_lst *lst_env, const char *name,
						const char *content);

/*
** Get
*/
char				*get_env_elem_content(t_lst *env, const char *name);
t_lst				*get_env_elem(t_lst *env, const char *name);

/*
** Delete
*/
void				del_env_elem(t_env **elem);
void				del_lst_env(t_lst **env);
t_lst				*del_lst_elem_by_name(t_lst *env, const char *name);

/*
** Tools
*/
int					ft_is_correct_env_name(char *str);
void				ft_disp_env(t_lst *env);

#endif
