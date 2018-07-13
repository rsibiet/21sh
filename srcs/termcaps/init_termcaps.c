/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:05:53 by mressier          #+#    #+#             */
/*   Updated: 2016/05/31 16:47:44 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "ft_sh.h"
#include <term.h>
#include <termios.h>

static void			term_set(t_term *term)
{
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_oflag &= ~(OPOST);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		exit(0);
}

int					init_termcaps(void)
{
	char	*name_term;
	t_term	term;

	if ((name_term = getenv("TERM")) == NULL)
		ft_puterror("TERM variable not found.\n");
	else if (tgetent(NULL, name_term) == -1)
		ft_puterror("Could not access the termcap data base.\n");
	else if (tcgetattr(0, &term) == -1)
		ft_puterror("Get parameters in termios structure failed.\n");
	else
	{
		term_set(&term);
		return (1);
	}
	return (-1);
}

t_link_cmd			init_cmd(t_cmd *cmd)
{
	t_link_cmd		link;

	ft_bzero(&link, sizeof(t_link_cmd));
	link.head = cmd;
	link.tail = cmd;
	return (link);
}
