/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 10:31:21 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/29 10:11:16 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

static int	ft_filladr(uintmax_t n, t_flags *f, int len)
{
	ft_filldimen_hex(f, len);
	if (n != 0 || (n == 0 && !(f->flags & HI_PRECISION)))
		ft_itoa_base_buff(n, "0123456789abcdef");
	return (0);
}

static int	ft_calladr(uintmax_t n, t_flags *f, int len)
{
	size_t	flen;

	flen = len;
	if (f->precision > len)
		flen = f->precision;
	flen += 2;
	if (f->buff_size)
	{
		if (f->flags & HI_MINUS)
		{
			ft_filladr(n, f, len);
			ft_fillbackward(f, 0, flen);
		}
		else
		{
			ft_fillforward_hex(f, flen);
			ft_filladr(n, f, len);
		}
	}
	else
		ft_filladr(n, f, len);
	return (1);
}

int			ft_call_filladr(va_list *ap, t_flags *f)
{
	uintmax_t	n;
	int			l;

	f->len_flags[0] = 'l';
	f->len_flags[1] = 0;
	f->type = 'x';
	f->flags |= HI_HASH;
	n = ft_get_uint(ap, f);
	if (n != 0)
		l = ft_len_nb(n, 16);
	else
	{
		if (f->flags & HI_PRECISION)
			l = 0;
		else
			l = 1;
	}
	return (ft_calladr(n, f, l));
}
