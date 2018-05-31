/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpychr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:02:31 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/06 20:04:24 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strcpychr(char *dst, const char *s, char c)
{
	char	*pos;

	*dst = '\0';
	if ((pos = ft_strchr(s, c)) == NULL)
		return (NULL);
	if (c != '\0')
		pos++;
	return (ft_strcpy(dst, pos));
}
