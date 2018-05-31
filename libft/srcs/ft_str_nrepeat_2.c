/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_nrepeat_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 23:44:41 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/01 23:48:19 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** char	*ft_str_nrepeat_2(const char *dst, const char *s, size_t n);
**
** DESCRIPTION
*/

char	*ft_str_nrepeat_2(char *dst, const char *s, size_t n)
{
	size_t	len;
	char	*cpy;

	if (s == NULL || dst == NULL)
		return (NULL);
	cpy = dst;
	len = ft_strlen(s);
	if (len)
	{
		while (n > len)
		{
			ft_strcpy(dst, s);
			dst += len;
			n -= len;
		}
		ft_strncpy(dst, s, n);
	}
	return (cpy);
}
