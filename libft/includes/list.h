/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:19:25 by mressier          #+#    #+#             */
/*   Updated: 2016/03/28 15:19:26 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct			s_db_list
{
	void				*data;
	struct s_db_list	*next;
	struct s_db_list	*prev;
}						t_db_lst;

typedef struct			s_lst
{
	void				*data;
	struct s_lst		*next;
}						t_lst;

/*
**  	------------------------------------------------------
**  	|						DB_LST	         	         |
**  	------------------------------------------------------
*/

int						ft_db_lst_len(t_db_lst *lst_ptr);
int						ft_db_lst_total_len(t_db_lst *ptr_lst);

t_db_lst				*ft_db_lst_new(void *data);
t_db_lst				*ft_db_lst_new_dup(void *data, size_t size);
t_db_lst				*ft_db_lst_new_empty(void);

t_db_lst				*ft_db_lst_add_after(t_db_lst *lst_ptr,
							t_db_lst *lst_to_add);
t_db_lst				*ft_db_lst_add_before(t_db_lst *lst_ptr,
							t_db_lst *lst_to_add);
t_db_lst				*ft_db_lst_add_start(t_db_lst *ptr_lst,
							t_db_lst *lst_to_add);
void					ft_db_lst_add_end(t_db_lst *lst, t_db_lst *lst_to_add);
t_db_lst				*ft_db_lst_add_index(t_db_lst *ptr_lst,
						t_db_lst *lst_to_add, int index);

t_db_lst				*ft_db_lst_get_last(t_db_lst	*ptr);
t_db_lst				*ft_db_lst_get_first(t_db_lst *ptr);
t_db_lst				*ft_db_lst_get_index(t_db_lst *ptr_lst, int index);

t_db_lst				*ft_db_lst_del(t_db_lst **lst_to_del,
							void (*del)(void **));
t_db_lst				*ft_db_lst_del_one(t_db_lst **lst_to_del,
							void (*del)(void **));
t_db_lst				*ft_db_lst_clr_one(t_db_lst *lst, void (*clr)(void *));
t_db_lst				*ft_db_lst_clr(t_db_lst *lst, void (*clr)(void *));
void					ft_db_lst_clr_all(t_db_lst *lst, void (*clr)(void *));

/*
**  	------------------------------------------------------
**  	|						LIST	         	         |
**  	------------------------------------------------------
*/

void					ft_move_lst_to_start(t_lst *to_move, t_lst **list);
void					ft_lst_del_one(t_lst **list, void (*del)(void **));
void					ft_lst_del(t_lst **list, void (*del)(void **));
t_lst					*ft_lst_new(void *new_file);
t_lst					*ft_lst_add_new(void *new_file,
							t_lst **ls_list);
t_lst					*ft_lst_get_last(t_lst *list);
t_lst					*ft_lst_add(t_lst *to_add, t_lst *list);
t_lst					*ft_lst_add_end(t_lst *new_lst, t_lst *list);
t_lst					*ft_lst_swap(t_lst *to_swap1, t_lst *to_swap2);
int						ft_lst_len(t_lst *lst);

#endif
