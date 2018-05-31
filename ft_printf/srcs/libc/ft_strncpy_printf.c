/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:52:00 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/07 09:37:59 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

static inline size_t	ft_n_process(size_t l, size_t n)
{
	if (l < n)
		return (l);
	else
		return (n);
}

char					*ft_strncpy_printf(char *dest, char const *s, size_t n,
	size_t l)
{
	size_t	i;
	size_t	*bdest;
	size_t	*bs;
	char	*r;

	r = dest;
	bdest = (size_t*)dest;
	bs = (size_t*)s;
	n = ft_n_process(l, n);
	i = 0;
	while (i < n / sizeof(size_t))
	{
		bdest[i] = bs[i];
		i++;
	}
	i = 0;
	dest = dest + n - n % sizeof(size_t);
	s = s + n - n % sizeof(size_t);
	while (i < n % sizeof(size_t))
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (r);
}
