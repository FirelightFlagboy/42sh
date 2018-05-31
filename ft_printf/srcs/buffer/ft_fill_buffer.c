/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:16:05 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 15:15:45 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"
#include "ft_printf_global.h"

char	*ft_putgen(t_flags *f, char const *s)
{
	if (f->flags & HI_BUFF_SIZE && (f->flags & HI_MINUS) == 0)
	{
		if (f->flags & HI_NULL)
			ft_add_nchar_to_buff('0', f->buff_size - 1);
		else
			ft_add_nchar_to_buff(' ', f->buff_size - 1);
	}
	if (*s)
		ft_add_char_to_buff(*s);
	if (f->flags & HI_BUFF_SIZE && f->flags & HI_MINUS)
		ft_add_nchar_to_buff(' ', f->buff_size - 1);
	return ((*s) ? (char*)s++ : (char*)s);
}

char	*ft_call_fc_g(char const *s, va_list *ap)
{
	t_flags f;
	int		i;

	ft_get_flags((char**)&s, ap, &f);
	i = 120 - f.type;
	if (i >= 0 && i <= PRINTF_SIZE_HASH)
	{
		if (g_conv[i](ap, &f) == -1)
			return (NULL);
		return ((char*)s);
	}
	return (ft_putgen(&f, s));
}

int		ft_fill_buffer(char const *s, va_list ap)
{
	t_buff	*buff;
	char	*p;
	size_t	len;
	va_list	node;

	buff = get_buff();
	va_copy(node, ap);
	while (*s != '\0')
	{
		p = ft_strchr_printf(s, '%');
		len = (p) ? p - s : ft_strlen_printf(s);
		ft_add_nstr_to_buff(s, len);
		s += len;
		if (*s)
			s = ft_call_fc_g(s, &node);
		if (!s)
			return (-1);
		if (*s == 0)
			break ;
		s++;
	}
	va_end(node);
	return (0);
}
