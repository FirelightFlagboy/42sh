/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:26:31 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 13:38:11 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_add_char_to_buff(int c)
{
	t_buff *buff;

	buff = get_buff();
	if (buff->index + 1 >= BUFF_SIZE_PRINTF)
		buff->put(buff);
	buff->buffer[buff->index++] = c;
	return (buff->index);
}

int		ft_add_nchar_to_buff(int c, size_t n)
{
	t_buff *buff;

	buff = get_buff();
	if (n + buff->index < BUFF_SIZE_PRINTF)
	{
		while (n > 0)
		{
			buff->buffer[buff->index++] = c;
			n--;
		}
		return (buff->index);
	}
	while (n > 0)
	{
		if (buff->index >= BUFF_SIZE_PRINTF)
			buff->put(buff);
		buff->buffer[buff->index++] = c;
		n--;
	}
	return (buff->index);
}

int		ft_add_str_to_buff(char const *s)
{
	t_buff	*buff;
	size_t	len;
	size_t	i;

	buff = get_buff();
	len = ft_strlen_printf(s);
	if (buff->index + len >= BUFF_SIZE_PRINTF)
		buff->put(buff);
	i = 0;
	while (i < len)
	{
		buff->buffer[buff->index + i] = *s++;
		i++;
	}
	buff->index += i;
	return (buff->index);
}

int		ft_add_nstr_to_buff(char const *s, size_t n)
{
	t_buff	*buff;

	buff = get_buff();
	if (n + buff->index < BUFF_SIZE_PRINTF)
	{
		while (n > 0)
		{
			buff->buffer[buff->index++] = *s++;
			n--;
		}
		return (buff->index);
	}
	while (n > 0)
	{
		if (buff->index >= BUFF_SIZE_PRINTF)
			buff->put(buff);
		buff->buffer[buff->index++] = *s++;
		n--;
	}
	return (buff->index);
}
