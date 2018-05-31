/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_cte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 09:59:55 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/09 10:23:10 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_len_nb_cte(uint32_t n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char					*ft_itoa_cte(int n)
{
	static char	res[34];
	uint32_t	d;
	uint8_t		neg;
	int64_t		len;

	d = n;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		d = -n;
	}
	len = ft_len_nb_cte(d) + neg;
	res[len--] = 0;
	while (len >= 0)
	{
		res[len--] = (d % 10) + '0';
		d /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
