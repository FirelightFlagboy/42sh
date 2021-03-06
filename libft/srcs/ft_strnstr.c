/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 06:01:04 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:21:09 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!*little && !*big)
	{
		return ((char *)big);
	}
	while (big[a] && (a < len))
	{
		b = 0;
		while (little[b] == big[a + b] && little[b] &&
				big[a + b] && ((a + b) < len))
			b++;
		if (!little[b])
			return ((char *)&big[a]);
		a++;
	}
	return (0);
}
