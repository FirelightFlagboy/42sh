/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:27:23 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/13 17:43:54 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** void *ft_memmove(void *dst, const void *src, size_t len);
**
** NAME
**	ft_memmove -- copy byte string
** DESCRIPTION
**	The ft_memmove() function copies len bytes from string src to string dst.
**	The two strings may overlap; the copy is always done in a non-destructive
**	manner.
** RETURN VALUES
**	The ft_memmove() function returns the original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	if (!len || dst == src)
		return (dst);
	s = (char *)src;
	d = (char *)dst;
	if (s > d)
		return (ft_memcpy(dst, src, len));
	d += len - 1;
	s += len - 1;
	while (len--)
		*d-- = *s--;
	return (dst);
}
