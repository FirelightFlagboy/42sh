/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 06:01:04 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:20:58 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** char	*ft_strnewcat(const char *s1, const char *s2);
**
** Using `ft_memcpy' instead of `ft_strcpy' and `ft_strcat' for performance
** reasons.
** It is the responsibility of the caller to free the memory when it is
** no longer needed.
*/

char	*ft_strnewcat(const char *s1, const char *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((s = ft_strnew(len1 + len2)) == NULL)
		return (NULL);
	ft_memcpy(s, s1, len1);
	ft_memcpy(s + len1, s2, len2 + 1);
	return (s);
}
