/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 09:35:08 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/28 13:32:47 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_fillnbr(uintmax_t n, t_flags *f, int len, char isneg)
{
	ft_filldimen(f, isneg, len);
	if (!(n == 0 && f->flags & HI_PRECISION && f->precision == 0))
		ft_itoa_buff(n);
	return (0);
}

int		ft_callnbr(uintmax_t n, t_flags *f, int len, char isneg)
{
	size_t		flen;

	flen = len;
	if (f->precision > len)
		flen = f->precision;
	if (f->flags & HI_PRECISION)
		f->flags &= ~HI_NULL;
	if (f->buff_size)
	{
		if (f->flags & HI_NULL && ((isneg && !(f->flags & HI_MINUS))))
			f->buff_size--;
		if (f->flags & HI_MINUS)
		{
			ft_fillnbr(n, f, len, isneg);
			return (ft_fillbackward(f, isneg, flen));
		}
		else
		{
			ft_fillforward(f, isneg, flen);
			return (ft_fillnbr(n, f, len, isneg));
		}
	}
	else
		return (ft_fillnbr(n, f, len, isneg));
}

int		ft_call_fillnbr(va_list *ap, t_flags *f)
{
	intmax_t	n;
	intmax_t	u;
	int			l;
	char		neg;

	n = ft_get_int(ap, f);
	l = ft_len_nb((n >= 0) ? n : -n, 10);
	if (f->flags & HI_PRECISION && n == 0 && f->precision == 0)
		l = 0;
	if (n < 0)
	{
		neg = 1;
		u = -n;
	}
	else
	{
		neg = 0;
		u = n;
	}
	if (n >= 0 && f->flags & HI_NULL && f->flags & (HI_ADD | HI_ESCAPE))
		f->buff_size--;
	return (ft_callnbr(u, f, l, neg));
}
