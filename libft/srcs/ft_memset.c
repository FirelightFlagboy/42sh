/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 22:06:33 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/10 23:06:39 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** void * ft_memset(void *b, int c, size_t len);
**
** NAME
**  ft_memset -- fill a byte string with a byte value
** DESCRIPTION
**	The ft_memset() function writes len bytes of value c (converted to an
**	unsigned char) to the string b.
** RETURN VALUES
**	The ft_memset() function returns its first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cpy;

	cpy = (unsigned char*)b;
	while (len--)
	{
		*cpy++ = (unsigned char)c;
	}
	return (b);
}
