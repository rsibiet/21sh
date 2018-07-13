/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libz.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:37:43 by mressier          #+#    #+#             */
/*   Updated: 2016/03/10 18:13:36 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBZ_H
# define LIBZ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/ioctl.h>
# include <limits.h>
# include "get_next_line.h"
# include "color.h"
# include "list.h"
# include "shell_env.h"
# include "ft_system.h"
# include "ft_signal.h"
# include "ft_error.h"

/*
**  	------------------------------------------------------
**  	|						ALLOCATIONS         	     |
**  	------------------------------------------------------
*/

char				**ft_str_tab_new(size_t nb_str, size_t size_str);
int					**ft_int_tab_new(size_t nb_column, size_t nb_line);

void				ft_intdel(int **int_tab);
void				ft_str_tab_del(char ***str);
void				ft_int_tab_del(int ***int_tab, size_t nb_line);

/*
**  	------------------------------------------------------
**  	|						MEMORY	         	         |
**  	------------------------------------------------------
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_malloc(size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memdup(const void *s, size_t n);
void				ft_memdel(void **ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**  	------------------------------------------------------
**  	|					      NB	         	         |
**  	------------------------------------------------------
*/

int					ft_unsigned_len(unsigned long long int nb, size_t base);
int					ft_signed_len(long long int nb, size_t base);
void				ft_swap(int *a, int *b);
int					ft_int_len(int nb);

/*
**  	------------------------------------------------------
**  	|						STRING	         	         |
**  	------------------------------------------------------
*/

/*
**	Modifications
*/

char				*ft_strnew(size_t size);

/*
** strdup
*/
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s2, size_t n);
char				*ft_strcdup(const char *s1, int c);

/*
** strcpy
*/
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(const char *dest, const char *src, size_t len);

/*
** strcat
*/
char				*ft_strcat(char *dest, const char *src);
char				*ft_str_concat_char(char *str, char c);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);

char				*ft_strsub(const char *s, unsigned int start, size_t len);

/*
** strtrim
*/
char				*ft_strtrim(const char *s);
char				*ft_strintrim(const char *s);

/*
** strsplit
*/
char				**ft_strsplit(const char *s, char c);
char				**ft_strsplit_ntime(const char *s, char c, int n);
char				**ft_strsplit_once(const char *str, char c);
char				**ft_strsplit_index(const char *s, int index);

/*
** strjoin
*/
char				*ft_strfjoin(char **s1, const char *s2);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strnfjoin(char **s1, const char *s2, size_t n);
char				*ft_strnjoin(const char *s1, const char *s2, size_t n);
char				*ft_strcfjoin(char **s1, const char *s2, char c);

/*
** clear, del
*/
void				ft_strclr(char *s);
void				ft_strdel(char **as);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));

char				*ft_search_and_replace_char(char *str, char *to_put, int c);
char				*ft_str_replace_in_str(const char *str, const char *to_rep,
						const char *new, int i);

void				ft_str_replace_str(char **s1, char *s2);

char				*ft_implode(char **str, int c);
char				**ft_explode(const char *str, int c);

char				*ft_cut_str(char *str, int start, int end);

/*
**	Research, cmp, ...
*/

int					ft_strclen(const char *s, int c);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strequ_end(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_strequ_caseins(const char *s1, const char *s2);
int					ft_count_char(const char *str, int c);

/*
**	Wchar & Wstr
*/

int					ft_wcharlen(wchar_t value);
wchar_t				*ft_wstrdup(const wchar_t *wstr);
size_t				ft_wstr_len(wchar_t	*wstr);

/*
**  	------------------------------------------------------
**  	|					  	  IS		       	         |
**  	------------------------------------------------------
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_is_sort_descend(int *int_tab, size_t size);
int					ft_is_sort_ascend(int *int_tab, size_t size);
int					ft_is_lower(int n1, int n2);
int					ft_is_higher(int n1, int n2);
int					ft_is_existing_file(const char *pathname);
int					ft_is_exec_file(const char *pathname);
int					ft_str_is_digit(char *str);
int					ft_is_directory(const char *pathname);
int					ft_is_sym_link(const char *pathname);
int					ft_str_is_only_digit(char *str);

/*
**  	------------------------------------------------------
**  	|					  CONVERSION	       	         |
**  	------------------------------------------------------
*/

char				*ft_itoa(int n);
int					ft_atoi(const char *nptr);
long long int		ft_atolli(const char *nptr);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_str_toupper(const char *str);
char				*ft_str_tolower(const char *str);
char				*ft_itoa_base(int nb, size_t base);
char				*ft_uitoa_base(unsigned int nb, size_t base);
char				*ft_llitoa_base(long long int nb, size_t base);
char				*ft_ullitoa_base(unsigned long long int nb, size_t base);
char				*ft_unctoa_base(unsigned char nb, size_t base);
char				*ft_unshrtoa_base(unsigned short nb, size_t base);

/*
**  	------------------------------------------------------
**  	|						ARRAY	         	         |
**  	------------------------------------------------------
*/

int					*ft_intnew(size_t size);
void				ft_rotate_down(int *int_tab, size_t size);
void				ft_rotate_up(int *int_tab, size_t size);
void				ft_go_up(int *int_tab, size_t size);
void				ft_go_down(int *int_tab, size_t size);
int					ft_find_the_lower(int *int_tab, size_t size);

int					ft_str_array_len(char **str);

/*
**  	------------------------------------------------------
**  	|						DISPLAY	         	         |
**  	------------------------------------------------------
*/

void				ft_putchar(char c);
void				ft_putnchar(size_t n, int c);
void				ft_putchar_fd(char c, int fd);

void				ft_putstr(const char *s);
void				ft_putnstr(const char *s, size_t n);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl(const char *s);
void				ft_putnstr_fd(const char *s, size_t n);
void				ft_putendl_fd(const char *s, int fd);

void				ft_putnbr(int nb);
void				ft_putnbrendl(int nb);
void				ft_putnbr_fd(int n, int fd);

void				ft_put_int_tab_fd(size_t nb_elem, int *int_tab, int fd);
void				ft_put_int_tab(size_t nb_elem, int *int_tab);
void				ft_put_str_tab_fd(char **s_tab, int fd);
void				ft_put_str_tab(char **s_tab);

void				ft_putwstr(const wchar_t *ws);
void				ft_putnwstr(const wchar_t *ws, int size);
int					ft_putwchar(wchar_t wc);

void				ft_puterror(const char *str);

void				ft_putstr_color(const char *color, const char *s);
void				ft_putstr_color_fd(const char *color, const char *s,
						int fd);
void				ft_putnbr_color(const char *color, int n);

/*
**  	------------------------------------------------------
**  	|						ARGUMENTS         	         |
**  	------------------------------------------------------
*/

void				*get_void_arg(va_list start, size_t nb_arg);
char				*get_str_arg(va_list start, size_t nb);
wchar_t				*get_wstr_arg(va_list start, size_t nb);
long long int		get_lli_arg(va_list start, size_t nb_arg);
long int			get_li_arg(va_list start, size_t nb);
int					get_int_arg(va_list start, size_t nb);
char				get_char_arg(va_list start, size_t nb);
wchar_t				get_wchar_arg(va_list start, size_t nb);
short				get_short_arg(va_list start, size_t nb);

/*
**  	------------------------------------------------------
**  	|						TERMINAL        	         |
**  	------------------------------------------------------
*/

size_t				get_terminal_nb_col(void);
size_t				get_terminal_nb_line(void);
int					*get_terminal_dimensions(void);
char				*create_new_path(char **path, const char *to_add);
char				*get_new_path(const char *path, const char *to_add);
char				*ft_get_host_name(void);
char				*ft_get_pwd(void);
char				*get_tilde_and_replace(char *cmd, t_lst *env);

#endif
