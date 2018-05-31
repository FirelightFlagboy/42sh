/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillforward_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:02:57 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/29 09:57:55 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_fillforward_float(t_flags *f, int neg, int len)
{
	int	flen;

	flen = f->buff_size - len;
	if (flen < 0)
		return (0);
	if (f->flags & HI_NULL)
	{
		if (neg)
			ft_add_char_to_buff('-');
		ft_add_nchar_to_buff('0', flen);
	}
	else
		ft_add_nchar_to_buff(' ', flen);
	return (0);
}
