/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:15:30 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/06 00:36:45 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsplitst_tmp(char *dst1, char *dst2, const char *s, char c)
{
	char	*pos;

	pos = NULL;
	while ((*dst1 = *s) != c && *dst1 != '\0')
	{
		s++;
		dst1++;
	}
	*dst2 = '\0';
	if (c != '\0' && *s == c)
	{
		pos = (char *)s;
		*dst1 = '\0';
		while ((*dst2 = *++s) != '\0')
			dst2++;
	}
	return (pos);
}

char	*ft_strsplitst(char **dst1, char **dst2, const char *s, char c)
{
	t_lens	l;

	if (dst1 == NULL || dst2 == NULL || s == NULL)
		return (NULL);
	l = ft_strlenschr(s, c);
	*dst1 = ft_strnew(l.a);
	*dst2 = ft_strnew(l.b);
	return (ft_strsplitst_tmp(*dst1, *dst2, s, c));
}
