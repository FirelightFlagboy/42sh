/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnpad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 03:57:40 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/03 16:17:43 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnpad_both(char *dst, const char *s, size_t n, const char *pad)
{
	char	*start;

	if (s == NULL || pad == NULL)
	{
		ft_strdel(&dst);
		return (NULL);
	}
	start = dst;
	ft_str_nrepeat_2(dst, pad, n);
	ft_strcpy((dst += n), s);
	ft_str_nrepeat_2(dst + ft_strlen(s), pad, n);
	return (start);
}

char	*ft_strnpad_right(char *dst, const char *s, size_t n, const char *pad)
{
	if (s == NULL || pad == NULL)
	{
		ft_strdel(&dst);
		return (NULL);
	}
	ft_strcpy(dst, s);
	ft_str_nrepeat_2(dst + ft_strlen(s), pad, n);
	return (dst);
}

char	*ft_strnpad_left(char *dst, const char *s, size_t n, const char *pad)
{
	if (s == NULL || pad == NULL)
	{
		ft_strdel(&dst);
		return (NULL);
	}
	ft_str_nrepeat_2(dst, pad, n);
	ft_strcpy(dst + n, s);
	return (dst);
}

char	*ft_strnpad(const char *s, size_t n, const char *pad, const int type)
{
	char	*new;

	if ((new = ft_strnew(ft_strlen(s) + 2 * n)) == NULL)
		return (NULL);
	if (type == STR_PAD_BOTH)
		ft_strnpad_both(new, s, n, pad);
	else if (type == STR_PAD_LEFT)
		ft_strnpad_left(new, s, n, pad);
	else if (type == STR_PAD_RIGHT)
		ft_strnpad_right(new, s, n, pad);
	return (new);
}
