/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 11:29:42 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/28 13:34:28 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

static char	*ft_get_char(int len, wchar_t c, char s[])
{
	if (len == 4)
	{
		s[0] = c / 0x40 / 0x40 / 0x40 + 0xf0;
		s[1] = (c / 0x40 / 0x40) % 0x40 + 0x80;
		s[2] = (c / 0x40) % 0x40 + 0x80;
		s[3] = c % 0x40 + 0x80;
	}
	else if (len == 3)
	{
		s[0] = c / 0x40 / 0x40 + 0xe0;
		s[1] = (c / 0x40) % 0x40 + 0x80;
		s[2] = c % 0x40 + 0x80;
	}
	else if (len == 2)
	{
		s[0] = c / 0x40 + 0xc0;
		s[1] = c % 0x40 + 0x80;
	}
	else
		s[0] = c;
	return (s);
}

int			ft_unicode(wchar_t c)
{
	char	s[5];
	int		l;

	l = ft_len_unicode(c);
	if (l == -1)
		return (-1);
	if (l == 1)
	{
		ft_add_char_to_buff(c);
		return (1);
	}
	s[l] = 0;
	ft_get_char(l, c, s);
	ft_add_str_to_buff(s);
	return (l);
}
