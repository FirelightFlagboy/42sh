/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:21:42 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/11 11:44:35 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** int ft_memcmp(const void *s1, const void *s2, size_t n);
**
** NAME
**	ft_memcmp -- compare byte string
** DESCRIPTION
**	The ft_memcmp() function compares byte string s1 against byte string s2.
**	Both strings are assumed to be n bytes long.
** RETURN VALUES
**	The ft_memcmp() function returns zero if the two strings are identical,
**	otherwise returns the difference between the first two differing bytes
**	(treated as unsigned char values, so that `\200' is greater than `\0', for
**	example). Zero-length strings are always identical.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_cpy;
	const unsigned char	*s2_cpy;

	s1_cpy = (const unsigned char *)s1;
	s2_cpy = (const unsigned char *)s2;
	while (n--)
		if (*s1_cpy++ != *s2_cpy++)
			return (*--s1_cpy - *--s2_cpy);
	return (0);
}
