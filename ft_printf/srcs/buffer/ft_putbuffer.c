/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:48:04 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/07 09:38:17 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

void		ft_putbuffer(t_buff *buff)
{
	buff->res += write(buff->fd, buff->buffer, buff->index);
	buff->index = 0;
}

void		ft_putbuffer_s(t_buff *buff)
{
	ft_strncpy_printf(buff->s + buff->res, buff->buffer, buff->index,
	buff->index);
	buff->res += buff->index;
	buff->index = 0;
}

void		ft_putbuffer_sn(t_buff *buff)
{
	size_t	max;

	max = buff->index;
	if (max > buff->max - buff->res)
		max = buff->max - buff->res;
	ft_strncpy_printf(buff->s + buff->res, buff->buffer, buff->max,
	buff->index);
	buff->res += max;
	buff->index = 0;
}

void		ft_putbuffer_as(t_buff *buff)
{
	size_t	len;
	size_t	flen;
	char	*r;

	len = buff->res;
	flen = len + buff->index;
	if (!(r = (char*)malloc((flen + 1) * sizeof(char))))
		return ;
	if (buff->s)
		ft_strncpy_printf(r, buff->s, len, buff->res);
	buff->buffer[buff->index + 1] = 0;
	ft_strncpy_printf(r + len, buff->buffer, buff->index, buff->index);
	r[flen] = 0;
	buff->res += buff->index;
	buff->index = 0;
	free(buff->s);
	buff->s = r;
}
