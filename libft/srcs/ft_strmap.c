/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 06:01:04 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:20:36 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		length;
	char	*string;
	char	*tmp;

	if (!s || !(*f))
		return (0);
	length = ft_strlen(s);
	tmp = NULL;
	if ((string = (char *)malloc(length + 1)))
	{
		tmp = string;
		while (*s)
		{
			*tmp = (*f)(*s);
			s++;
			tmp++;
		}
	}
	else
		return (0);
	*tmp = '\0';
	return (string);
}
