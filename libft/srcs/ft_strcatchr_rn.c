/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatchr_rn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:46:54 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

#include <stdio.h>

char	*ft_strcatchr_rn(char **d, const char *s, char c)
{
	char	*new;
	size_t	l1;
	size_t	l2;

	if (d == NULL)
		return (NULL);
	l1 = ft_strlen_nul(*d);
	l2 = ft_strlenchr(s, c);
	if ((new = ft_strnew(l1 + l2)) == NULL)
		return (NULL);
	ft_memcpy(new, *d, l1);
	free(*d);
	ft_strchrcpy(new + l1, s, c);
	*d = new;
	return (new);
}
