/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 03:25:02 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/09 23:24:35 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** char *ft_strpad(char *s, size_t len, char *pad, unsigned int type)
**
** It is the responsibility of the caller to free the memory when it is
** no longer needed
*/

char	*ft_strpad_both(char *dst, const char *s, size_t len, const char *pad)
{
	size_t	remainder;
	char	*start;

	start = dst;
	if (s == NULL || pad == NULL)
	{
		ft_strdel(&dst);
		return (NULL);
	}
	remainder = len % 2;
	len /= 2;
	ft_str_nrepeat_2(dst, pad, len);
	dst += len;
	ft_strcpy(dst, s);
	ft_str_nrepeat_2(dst + ft_strlen(s), pad, len + remainder);
	return (start);
}

char	*ft_strpad_right(char *dst, const char *s, size_t len, const char *pad)
{
	if (s == NULL || pad == NULL)
	{
		ft_strdel(&dst);
		return (NULL);
	}
	ft_strcpy(dst, s);
	ft_str_nrepeat_2(dst + ft_strlen(s), pad, len);
	return (dst);
}

char	*ft_strpad_left(char *dst, const char *s, size_t len, const char *pad)
{
	if (s == NULL || pad == NULL)
	{
		ft_strdel(&dst);
		return (NULL);
	}
	ft_str_nrepeat_2(dst, pad, len);
	ft_strcpy(dst + len, s);
	return (dst);
}

char	*ft_strpad(const char *s, size_t len, const char *pad, const int type)
{
	char	*new;
	size_t	slen;

	slen = ft_strlen(s);
	if (len <= slen)
		return (ft_strdup(s));
	if ((new = ft_strnew(len)) == NULL)
		return (NULL);
	len -= slen;
	if (type == STR_PAD_BOTH)
		ft_strpad_both(new, s, len, pad);
	else if (type == STR_PAD_LEFT)
		ft_strpad_left(new, s, len, pad);
	else if (type == STR_PAD_RIGHT)
		ft_strpad_right(new, s, len, pad);
	return (new);
}
