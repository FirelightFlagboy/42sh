/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:39:47 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str3join(char *s1, char *s2, char *s3)
{
	char	*result;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if ((result = ft_strnew(length)))
	{
		while (s1 && *s1)
			result[i++] = *s1++;
		while (s2 && *s2)
			result[i++] = *s2++;
		while (s3 && *s3)
			result[i++] = *s3++;
		return (result);
	}
	else
		return (NULL);
}
