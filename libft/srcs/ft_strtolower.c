/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:53:56 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/03 17:54:58 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnewlow(const char *s)
{
	char	*new;
	char	*start;

	if ((new = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	start = new;
	while (*s != '\0')
		*new++ = ft_ctolower(*s++);
	return (start);
}

char	*ft_strtolower(char *s)
{
	char	*start;

	start = s;
	while (*s != '\0')
	{
		if (ft_isupper(*s))
			*s += 'a' - 'A';
		s++;
	}
	return (start);
}
