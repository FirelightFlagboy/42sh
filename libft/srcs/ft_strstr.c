/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 06:01:04 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:21:23 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	a;
	int	b;

	a = 0;
	if (!*little && !*big)
		return ((char *)big);
	while (big[a])
	{
		b = 0;
		while (little[b] == big[a + b] && little[b] && big[a + b])
			b++;
		if (!little[b])
			return ((char *)&big[a]);
		a++;
	}
	return (0);
}
