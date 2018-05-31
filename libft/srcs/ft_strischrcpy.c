/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strischrcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:14:37 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/09 23:22:59 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strischrcpy(char *dst, const char *src, const int c, int *ret)
{
	char		*s;
	const char	*start;
	int			i;

	i = 0;
	s = dst;
	start = src;
	while ((*s = *src++) != '\0')
	{
		i++;
		if (*s == c)
		{
			*s = '\0';
			*ret = i;
			return ((char *)src);
		}
		s++;
	}
	*ret = i;
	return (NULL);
}
