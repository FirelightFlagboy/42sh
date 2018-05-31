/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:47:39 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 15:58:40 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int			ft_vsprintf(char *s, char *format, va_list ap)
{
	va_list	node;
	t_buff	*buff;

	buff = get_buff();
	buff->index = 0;
	buff->res = 0;
	buff->s = s;
	buff->put = ft_putbuffer_s;
	va_copy(node, ap);
	if (ft_fill_buffer(format, node) != -1)
		buff->put(buff);
	else
		return (-1);
	va_end(node);
	return (buff->res);
}

int			ft_vsnprintf(char *s, size_t n, char *format, va_list ap)
{
	va_list	node;
	t_buff	*buff;

	buff = get_buff();
	buff->index = 0;
	buff->res = 0;
	buff->s = s;
	buff->max = n;
	buff->put = ft_putbuffer_sn;
	va_copy(node, ap);
	if (ft_fill_buffer(format, node) != -1)
		buff->put(buff);
	else
		return (-1);
	va_end(node);
	return (buff->res);
}

int			ft_vasprintf(char **as, char *format, va_list ap)
{
	va_list	node;
	t_buff	*buff;

	buff = get_buff();
	buff->index = 0;
	buff->res = 0;
	*as = NULL;
	buff->s = NULL;
	buff->put = ft_putbuffer_as;
	va_copy(node, ap);
	if (ft_fill_buffer(format, node) != -1)
		buff->put(buff);
	else
		return (-1);
	va_end(node);
	*as = buff->s;
	return (buff->res);
}
