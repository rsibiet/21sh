/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:59:16 by mressier          #+#    #+#             */
/*   Updated: 2016/01/28 16:59:18 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libz.h"

wchar_t		*ft_wstrdup(const wchar_t *wstr)
{
	wchar_t	*new_wstr;
	wchar_t	*ret;

	new_wstr = ft_memalloc((ft_wstr_len((wchar_t *)wstr) + 1)
		* sizeof(wchar_t));
	ret = new_wstr;
	new_wstr = ft_memcpy(new_wstr, wstr,
		((ft_wstr_len((wchar_t *)wstr) + 1) * sizeof(wchar_t)));
	return (ret);
}
