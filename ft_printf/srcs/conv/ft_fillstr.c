/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 10:54:34 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/29 16:19:00 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_fill_longstr(wchar_t *ls, int n)
{
	int	res;
	int	l;
	int	i;
	int	s;

	i = -1;
	res = 0;
	s = n;
	if (!n)
		return (0);
	while (ls[++i] && (s > 0))
	{
		l = ft_len_unicode(ls[i]);
		if (res + l > n)
			return (res);
		res += ft_unicode(ls[i]);
		s -= l;
	}
	return (res);
}

int		ft_callstr(char *s, t_flags *f, int len)
{
	size_t	flen;

	flen = len;
	if (f->flags & HI_PRECISION && f->precision < len)
		flen = f->precision;
	if (f->buff_size)
	{
		if (f->flags & HI_MINUS)
		{
			ft_add_nstr_to_buff(s, flen);
			ft_fillbackward(f, 0, flen);
		}
		else
		{
			ft_fillforward(f, 0, flen);
			ft_add_nstr_to_buff(s, flen);
		}
	}
	else
		ft_add_nstr_to_buff(s, flen);
	return (1);
}

int		ft_call_longstr(wchar_t *s, t_flags *f)
{
	long	flen;

	flen = ft_get_finale_len(s, f);
	if (flen == -1)
		return (-1);
	if (f->flags & HI_PRECISION && ft_len_unicode(*s) > f->precision)
		flen = 0;
	if (f->buff_size)
	{
		if (f->flags & HI_MINUS)
		{
			ft_fill_longstr(s, flen);
			ft_fillbackward(f, 0, flen);
		}
		else
		{
			ft_fillforward(f, 0, flen);
			ft_fill_longstr(s, flen);
		}
	}
	else
		ft_fill_longstr(s, flen);
	return (1);
}

int		ft_call_fill_longstr(va_list *ap, t_flags *f)
{
	wchar_t *s;

	s = (wchar_t*)va_arg(*ap, wchar_t*);
	f->flags &= ~(HI_ADD | HI_ESCAPE);
	if (s == NULL)
		return (ft_callstr("(null)", f, 6));
	return (ft_call_longstr(s, f));
}

int		ft_call_fillstr(va_list *ap, t_flags *f)
{
	char	*s;

	if (f->len_flags[0] == 'l' && f->len_flags[1] == 0)
		return (ft_call_fill_longstr(ap, f));
	s = (char*)va_arg(*ap, char*);
	f->flags &= ~(HI_ADD | HI_ESCAPE);
	if (s == NULL)
		return (ft_callstr("(null)", f, 6));
	return (ft_callstr(s, f, ft_strlen_printf(s)));
}
