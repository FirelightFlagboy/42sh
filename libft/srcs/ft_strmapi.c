/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 06:01:04 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:20:38 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	length;
	char			*string;
	char			*tmp;
	int				index;

	index = 0;
	if (!s || !(*f))
		return (0);
	length = ft_strlen(s);
	tmp = NULL;
	if ((string = (char *)malloc(length + 1)))
	{
		tmp = string;
		while (*s)
		{
			*tmp = (*f)(index, *s);
			s++;
			tmp++;
			index++;
		}
	}
	else
		return (0);
	*tmp = '\0';
	return (string);
}
