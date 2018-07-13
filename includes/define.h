/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 18:09:39 by mressier          #+#    #+#             */
/*   Updated: 2016/05/19 13:34:26 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFINE_H
# define FT_DEFINE_H

# include "../libft/includes/libz.h"

# define SHELL 		"21sh"
# define DEF_USR	"marvin"

# define CHILD 		0
# define READ		0
# define WRITE		1

/*
** builtin
*/
# define ENV 		"env"
# define EXIT 		"exit"
# define SETENV 	"setenv"
# define UNSETENV 	"unsetenv"
# define CD 		"cd"
# define HELP		"help"
# define HASHTABLE	"hashtable"

enum					e_builtin
{
	BT_ENV = 0,
	BT_SETENV,
	BT_UNSETENV,
	BT_CD,
	NB_BUILTIN,
	BT_OTHER,
	BT_HASHTABLE,
	BT_UNKNOW
};

/*
** cd builtin
*/
# define ENV_FLAG_I	0
# define ENV_FLAG_V	1
# define NB_FLAGS	2

/*
** Separator char
*/
# define SEMI_COLONS	';'
# define REDIR_RIGHT	'>'
# define DB_REDIR_RIGHT	'R'
# define DB_REDIR_LEFT	'L'
# define REDIR_LEFT		'<'
# define C_PIPE			'|'
# define DB_QUOTE		'"'
# define QUOTE			'\''
# define BCKQUOTE		'`'
# define OPEN_PAR		'('
# define CLOSE_PAR		')'
# define REDIR_RIGHT_ET	'r'
# define REDIR_LEFT_ET	'l'

/*
** A faire
*/
# define C_OU 			'O'
# define C_ET 			'E'

/*
** Builtin
*/

typedef t_lst *			(*t_ft_builtin)(char **, t_lst *);

enum					e_type_cmd
{
	BUILT_IN = 0,
	OTHER,
	NOTHING
};

typedef struct			s_bin
{
	int					ope;
	char				*cmd;
	struct s_bin		*right;
	struct s_bin		*left;
	struct s_bin		*node;
}						t_bin;

/*
** env
*/
# define LST_ENV			t_lst

/*
** structure totale
*/
typedef struct			s_core
{
	LST_ENV				*env;
}						t_core;

#endif
