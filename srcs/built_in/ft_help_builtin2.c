/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_builtin2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:23:53 by rsibiet           #+#    #+#             */
/*   Updated: 2016/06/02 14:54:30 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void				disp_termcaps(void)
{
	ft_pc(C_G_GREEN, "\t*************************************************\n");
	ft_pc(C_G_GREEN, "\t|\t\t\tTERMCAPS\t\t|\n");
	ft_pc(C_G_GREEN, "\t*************************************************\n");
	ft_putendl("\n\t- Move the cursor (left, right): Arrow left / right");
	ft_putendl("\t- Navigate inside historical commands: Arrow up / down");
	ft_putendl("\t- copy / paste text: command c / command v");
	ft_putendl("\t- copy/paste/cut text in line: option c/v/x and arrows");
	ft_putendl("\t- Move word by word: option + arrow left / right");
	ft_putendl("\t- home: put the cursor at the beginning of line");
	ft_putendl("\t- end: put the cursor at end of line");
	ft_putendl("\t- '\"`({ must be closed to send command");
	ft_putendl("\t- Ctrl D");
	ft_putendl("\t- Ctrl L to clear the screen\n");
}

void				disp_syntax(void)
{
	ft_pc(C_G_CYAN, "\t*************************************************\n");
	ft_pc(C_G_CYAN, "\t|\t\t\tSYNTAX\t\t\t|\n");
	ft_pc(C_G_CYAN, "\t*************************************************\n");
	ft_putendl("\n\t- ';'");
	ft_putendl("\t- '|'");
	ft_putendl("\t- '>' '<'");
	ft_putendl("\t- '>>' '<<'");
	ft_putendl("\t- '>&' '<&'");
	ft_putendl("\t- quotes, dbquotes\n");
}
