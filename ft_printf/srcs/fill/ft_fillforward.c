/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillforward.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:53:06 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/28 13:33:19 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_fillforward(t_flags *f, char isneg, int len)
{
	int	l;

	l = ft_get_len_forward(f, len, isneg);
	if (f->flags & HI_NULL\
	&& (isneg || ((f->flags & (HI_ADD | HI_ESCAPE)) && !isneg)))
		ft_fill_char_sign(f, isneg);
	if (f->flags & HI_NULL)
		ft_add_nchar_to_buff('0', l);
	else
		ft_add_nchar_to_buff(' ', l);
	return (l);
}

int		ft_fillforward_hex(t_flags *f, int len)
{
	int	l;

	if (f->flags & HI_HASH && f->flags & HI_NULL)
		ft_fill_ox(f->type);
	if (f->buff_size < len)
		return (0);
	l = f->buff_size - len;
	if (f->flags & HI_NULL)
		ft_add_nchar_to_buff('0', l);
	else
		ft_add_nchar_to_buff(' ', l);
	return (l);
}

int		ft_fillforward_uin(t_flags *f, int len)
{
	int	l;

	if (f->buff_size < len)
		return (0);
	l = f->buff_size - len;
	if (f->flags & HI_NULL)
		ft_add_nchar_to_buff('0', l);
	else
		ft_add_nchar_to_buff(' ', l);
	return (l);
}

int		ft_fillforward_oct(t_flags *f, int len)
{
	int l;

	if (f->buff_size < len)
		return (0);
	l = f->buff_size - len + (f->flags & HI_NULL && f->flags & HI_HASH);
	if (f->flags & HI_NULL)
		ft_add_nchar_to_buff('0', l);
	else
		ft_add_nchar_to_buff(' ', l);
	return (l);
}
