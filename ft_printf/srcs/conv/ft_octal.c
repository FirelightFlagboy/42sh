/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 09:28:30 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/28 13:32:52 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_filloctal(uintmax_t n, t_flags *f, int len)
{
	ft_filldimen_oct(f, len);
	if (n != 0)
		ft_itoa_base_buff(n, "01234567");
	return (0);
}

int		ft_calloctal(uintmax_t n, t_flags *f, int len)
{
	size_t	flen;

	flen = len;
	if (f->precision > len)
		flen = f->precision;
	if (f->flags & HI_HASH)
		flen++;
	if (f->buff_size)
	{
		if (f->flags & HI_MINUS)
		{
			ft_filloctal(n, f, len);
			ft_fillbackward(f, 0, flen);
		}
		else
		{
			ft_fillforward_hex(f, flen);
			ft_filloctal(n, f, len);
		}
	}
	else
		ft_filloctal(n, f, len);
	return (0);
}

int		ft_call_filloctal(va_list *ap, t_flags *f)
{
	uintmax_t	n;
	int			l;

	n = ft_get_uint(ap, f);
	if (n)
		l = ft_len_nb(n, 8);
	else
	{
		l = 0;
		if ((f->flags & HI_PRECISION) == 0)
			f->flags |= HI_HASH;
	}
	return (ft_calloctal(n, f, l));
}
