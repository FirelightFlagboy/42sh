/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_repeat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 00:43:20 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/01 22:49:39 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

/*
** char	*ft_str_repeat(const char *s, size_t n)
**
** DESCRIPTION
**	Returns input repeated multiplier times.
** Param. #1 - const char s
**	The string to be repeated.
** Param. #2 - size_t n
**	Number of time the input string should be repeated.
**	n has to be greater than or equal to 0.
**	If the multiplier is set to 0, the function will return an empty string.
** RETURN
**	Returns the repeated string.
** EXAMPLES
**	The following sets `newstr' to ``-=-=-=-=-=-=-=-=-=-=''
**		char *newstr = ft_str_repeat("-=", 10);
*/

char	*ft_str_repeat(const char *s, size_t n)
{
	char		*repeat;
	char		*cpy;
	size_t		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((repeat = ft_strnew(n * len)) == NULL)
		return (NULL);
	cpy = repeat;
	if (len)
	{
		while (n--)
		{
			ft_strcpy(repeat, s);
			repeat += len;
		}
	}
	return (cpy);
}
