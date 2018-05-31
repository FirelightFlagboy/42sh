/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:56:05 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/03 17:56:39 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnewup(const char *s)
{
	char	*new;
	char	*start;

	if ((new = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	start = new;
	while (*s != '\0')
		*new++ = ft_ctoupper(*s++);
	return (start);
}

char	*ft_strtoupper(char *s)
{
	char	*start;

	start = s;
	while (*s != '\0')
	{
		if (ft_islower(*s))
			*s -= 'a' - 'A';
		s++;
	}
	return (start);
}
