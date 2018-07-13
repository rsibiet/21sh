/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:46:47 by mressier          #+#    #+#             */
/*   Updated: 2016/06/02 14:53:23 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void				ft_put(const char *s1, const char *s2)
{
	ft_putstr(s1);
	ft_putendl(s2);
}

static void				disp_builtin(void)
{
	ft_pc(C_G_RED, "\t*************************************************\n");
	ft_pc(C_G_RED, "\t|\t\t\tBUILTIN\t\t\t|\n");
	ft_pc(C_G_RED, "\t*************************************************\n\n");
	ft_put("\t- ", ENV);
	ft_putendl("\t\tUsage : env [iv] [name=value] [utility [arg ...]]");
	ft_put("\t- ", SETENV);
	ft_putendl("\t\tsetenv name value");
	ft_put("\t- ", UNSETENV);
	ft_putendl("\t\tunsetenv value [value value...]");
	ft_put("\t- ", CD);
	ft_putendl("\t\tUsage : cd [-PL][-|<dir>]");
	ft_put("\t- ", EXIT);
	ft_putendl("\t\texit [value 0-255]\n");
	ft_put("\t- ", HASHTABLE);
	ft_putendl("\t\tdisp the hashtable\n");
}

static void				disp_signaux(void)
{
	ft_pc(C_G_YELLOW, "\t*************************************************\n");
	ft_pc(C_G_YELLOW, "\t|\t\t\tSIGNAUX\t\t\t|\n");
	ft_pc(C_G_YELLOW, "\t*************************************************\n");
	ft_putendl("\n\tSignal catch : ");
	ft_putstr("\t- Ctrl C");
	ft_putstr("\t- Ctrl Z");
	ft_putstr("\t- Ctrl \\\n\n");
}

static void				disp_others(void)
{
	ft_pc(C_G_BLUE, "\t*************************************************\n");
	ft_pc(C_G_BLUE, "\t|\t\t\tOTHERS\t\t\t|\n");
	ft_pc(C_G_BLUE, "\t*************************************************\n\n");
	ft_putendl("\tThis minishell is handling : ");
	ft_putendl("\t\t- The tilde (~)");
	ft_putendl("\t\t- The $var notation");
	ft_putendl("\t\t- It increase the SHLVL value each time");
	ft_putendl("\t\t- Look at this prompt :D");
	ft_put("\n Got a path : ", BASIC_PATH);
}

void					ft_help_builtin(void)
{
	disp_help();
	disp_builtin();
	disp_signaux();
	disp_termcaps();
	disp_syntax();
	disp_others();
}
