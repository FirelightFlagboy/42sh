/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:14:54 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/10 23:26:18 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** void *ft_memccpy(void *dst, const void *src, int c, size_t n);
**
** NAME
**	ft_memccpy -- copy string until character found
** DESCRIPTION
**	The ft_memccpy() function copies bytes from string src to string dst.
**	If the character c (as converted to an unsigned char) occurs
**	in the string src, the copy stops and a pointer
**	to the byte after the copy of c in the string dst is returned.
**	Otherwise, n bytes are copied, and a NULL pointer is returned.
**	The source and destination strings should not overlap, as the behavior
**	is undefined.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*d;
	char			*s;
	unsigned char	ch;

	s = (char *)src;
	d = (char *)dst;
	ch = (unsigned char)c;
	while (n--)
	{
		if ((*d++ = *s++) == c)
			return (d);
	}
	return (NULL);
}
