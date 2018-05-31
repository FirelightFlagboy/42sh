/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:54:54 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 15:15:23 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

t_flags		*ft_get_att(char **astr, t_flags *f)
{
	char	*s;

	s = *astr;
	while (ft_isatt_flags(*s))
	{
		if (*s == '#')
			f->flags |= HI_HASH;
		else if (*s == ' ')
			f->flags |= HI_ESCAPE;
		else if (*s == '-')
			f->flags |= HI_MINUS;
		else if (*s == '+')
			f->flags |= HI_ADD;
		else if (*s == '0')
			f->flags |= HI_NULL;
		s++;
	}
	*astr = s;
	return (f);
}

t_flags		*ft_get_flags(char **astr, va_list *ap, t_flags *f)
{
	char	*s;

	s = *astr;
	s++;
	f->flags = 0;
	f->buff_size = 0;
	f->precision = 0;
	ft_get_att(&s, f);
	ft_get_buff_size(&s, f, ap);
	ft_get_precision(&s, f, ap);
	ft_get_len_flags(&s, f);
	f->type = *s;
	*astr = s;
	return (f);
}
