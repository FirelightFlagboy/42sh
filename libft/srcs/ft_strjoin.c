/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 06:01:04 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:20:22 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	char	*tmp;

	tmp = NULL;
	if (s1 && s2)
	{
		if ((string = (char *)malloc(ft_strlen((char *)s1) +
			ft_strlen((char *)s2) + 1)))
		{
			tmp = string;
			while (*s1)
				*tmp++ = *s1++;
			while (*s2)
				*tmp++ = *s2++;
			*tmp = '\0';
		}
		else
			return (0);
		return (string);
	}
	else if (s1 && !s2)
		return (ft_strdup((char*)s1));
	else if (!s1 && s2)
		return (ft_strdup((char*)s2));
	return (NULL);
}
