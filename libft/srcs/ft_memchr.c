/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:07:02 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/11 11:51:50 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** void *ft_memchr(const void *s, int c, size_t n);
**
** NAME
**	memchr -- locate byte in byte string
** DESCRIPTION
**	The ft_memchr() function locates the first occurrence of c (converted to
**	an unsigned char) in string s.
** RETURN VALUES
**	The ft_memchr() function returns a pointer to the byte located, or NULL
**	if no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char *)s;
	while (n--)
	{
		if (*src == (unsigned char)c)
			return (src);
		src++;
	}
	return (NULL);
}
