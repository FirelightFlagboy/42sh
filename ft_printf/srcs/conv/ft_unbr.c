/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:06:22 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/28 13:32:55 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_fillunbr(uintmax_t n, t_flags *f, int len)
{
	if (f->precision)
		ft_filldimen_uin(f, len);
	if (!(n == 0 && f->flags & HI_PRECISION && f->precision == 0))
		ft_itoa_buff(n);
	return (0);
}

int		ft_callunbr(uintmax_t n, t_flags *f, int len)
{
	size_t	flen;

	flen = len;
	if (f->precision > len)
		flen = f->precision;
	if (f->flags & HI_PRECISION)
		f->flags &= ~HI_NULL;
	if (f->buff_size)
	{
		if (f->flags & HI_MINUS)
		{
			ft_fillunbr(n, f, len);
			ft_fillbackward(f, 0, flen);
		}
		else
		{
			ft_fillforward_uin(f, flen);
			ft_fillunbr(n, f, len);
		}
	}
	else
		ft_fillunbr(n, f, len);
	return (1);
}

int		ft_call_fillunbr(va_list *ap, t_flags *f)
{
	uintmax_t	n;
	int			l;

	n = ft_get_uint(ap, f);
	l = ft_len_nb(n, 10);
	if (f->flags & HI_PRECISION && n == 0 && f->precision == 0)
		l = 0;
	f->flags &= ~HI_ADD;
	return (ft_callunbr(n, f, l));
}
