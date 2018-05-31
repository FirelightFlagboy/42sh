/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 22:38:12 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/10 22:47:22 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** void ft_bzero(void *s, size_t n);
**
** NAME
**	ft_bzero -- write zeroes to a byte string
** DESCRIPTION
**	The ft_bzero() function writes n zeroed bytes to the string s.
**	If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	char	*cpy;

	cpy = (char *)s;
	while (n--)
	{
		*cpy++ = 0;
	}
}
