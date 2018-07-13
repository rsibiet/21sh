/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:49:18 by mressier          #+#    #+#             */
/*   Updated: 2016/05/09 15:49:19 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

static char			**ft_file_error(char **msg)
{
	msg[NO_FILE_OR_DIR] = ft_strdup("no such file or directory");
	msg[NOT_DIR] = ft_strdup("not a directory");
	msg[NO_HOME_DIR] = ft_strdup("No home directory");
	msg[NO_PREVIOUS_DIR] = ft_strdup("No previous directory");
	msg[IS_DIR] = ft_strdup("is a directory");
	return (msg);
}

static char			**access_error(char **msg)
{
	msg[PERM_DENIED] = ft_strdup("permission denied");
	msg[COMMAND_NOT_FOUND] = ft_strdup("command not found");
	msg[BAD_FD] = ft_strdup("bad file descriptor");
	msg[EXEC_FORMAT_ERROR] = ft_strdup("exec format error");
	return (msg);
}

static char			**parsing_error(char **msg)
{
	msg[TOO_MANY_ARG] = ft_strdup("Too many arguments");
	msg[TOO_FEW_ARG] = ft_strdup("Too few arguments");
	msg[EXPR_SYNTAX] = ft_strdup("Expression syntax");
	msg[NAME_WTHONLY_ALPHANUM_CHAR] =
		ft_strdup("Variable name must contain alphanumeric characters.");
	msg[INVALID_ARG] = ft_strdup("Invalid arguments");
	msg[NULL_CMD] = ft_strdup("Invalid null command");
	msg[PARSING_ERROR] = ft_strdup("parsing error near");
	msg[FILE_NB_EXPECT] = ft_strdup("File number expected");
	return (msg);
}

static char			**exec_error(char **msg)
{
	msg[FORK_ERROR] = ft_strdup("fork fail");
	msg[PIPE_ERROR] = ft_strdup("pipe fail");
	return (msg);
}

char				**get_all_messages(void)
{
	char	**msg;

	msg = ft_memalloc(sizeof(char *) * (NB_ERROR + 1));
	msg = ft_file_error(msg);
	msg = access_error(msg);
	msg = parsing_error(msg);
	msg = exec_error(msg);
	return (msg);
}
