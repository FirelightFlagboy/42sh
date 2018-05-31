/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 21:02:21 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/13 17:25:18 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	if (dst == NULL || src == NULL)
		return (0);
	len = 1;
	while ((len++ < size) && *src)
		*dst++ = *src++;
	if (size)
		*dst = '\0';
	while (*src++)
		len++;
	return (len - 2);
}
