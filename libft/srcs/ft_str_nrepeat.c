/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_nrepeat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:14:11 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:52:28 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** char	*ft_str_nrepeat(const char *s, size_t n);
**
** DESCRIPTION
*/

char	*ft_str_nrepeat(const char *s, size_t n)
{
	size_t	len;
	char	*cpy;
	char	*repeat;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((repeat = ft_strnew(n)) == NULL)
		return (NULL);
	cpy = repeat;
	if (len)
	{
		while (n > len)
		{
			ft_strcpy(repeat, s);
			repeat += len;
			n -= len;
		}
		ft_strncpy(repeat, s, n);
	}
	return (cpy);
}
