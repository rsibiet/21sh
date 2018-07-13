/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twodim_tab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:22:47 by mressier          #+#    #+#             */
/*   Updated: 2016/03/28 15:22:49 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWODIM_TAB_H
# define TWODIM_TAB_H

typedef struct		s_twodim_tab
{
	int				**tab;
	int				line;
	int				column;
}					t_twodim_tab;

t_twodim_tab		*ft_twodim_tab_new(int **tab, size_t column, size_t line);
void				ft_twodim_tab_del(t_twodim_tab **tab);

void				ft_put_twodim_tab(t_twodim_tab *tab);
void				ft_put_twodim_tab_fd(t_twodim_tab *tab, int fd);

#endif
