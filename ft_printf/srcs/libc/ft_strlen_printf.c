/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:36:09 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/27 13:59:26 by ybensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int			ft_len_unicode(wchar_t n)
{
	int	l;

	l = -1;
	if (n >= 0 && n < 0x80)
		l = 1;
	else if (n < 0x800)
		l = 2;
	else if (n < 0x10000)
		l = 3;
	else if (n < 0x200000)
		l = 4;
	if (l <= MB_CUR_MAX)
		return (l);
	return (-1);
}

size_t		ft_strlen_printf(char const *str)
{
	char const *s;

	s = str;
	while (*str)
		str++;
	return (str - s);
}

int			ft_get_finale_len(wchar_t *s, t_flags *f)
{
	int len;
	int l;

	len = 0;
	while (*s)
	{
		l = ft_len_unicode(*s);
		if (l == -1)
			return (-1);
		if (f->flags & HI_PRECISION && len + l > f->precision)
			break ;
		len += l;
		s++;
	}
	return (len);
}
