/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:24:55 by mressier          #+#    #+#             */
/*   Updated: 2016/05/09 15:24:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

enum				e_error
{
	NO_FILE_OR_DIR = 0,
	NOT_DIR,
	NO_HOME_DIR,
	NO_PREVIOUS_DIR,
	PERM_DENIED,
	TOO_MANY_ARG,
	TOO_FEW_ARG,
	EXPR_SYNTAX,
	NAME_WTHONLY_ALPHANUM_CHAR,
	INVALID_ARG,
	COMMAND_NOT_FOUND,
	PARSING_ERROR,
	FORK_ERROR,
	PIPE_ERROR,
	NULL_CMD,
	FILE_NB_EXPECT,
	BAD_FD,
	EXEC_FORMAT_ERROR,
	IS_DIR,
	NB_ERROR,
	NO_ERROR
};

/*
** ft_error.c
*/
enum e_error		get_error(void);
void				set_error(enum e_error error);
char				*get_str_error(void);
void				set_str_error(char *str);

/*
** ft_tools_error.c
*/
void				set_perror(char *str, enum e_error error);
void				ft_put_error_message(enum e_error error);

/*
** message_error.c
*/
char				**get_all_messages(void);
void				ft_perror(const char *str);

#endif
