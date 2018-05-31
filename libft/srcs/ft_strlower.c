/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:22:27 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:54:49 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strlower(char *s)
{
	int		i;
	int		len;

	if (s)
	{
		len = (int)ft_strlen(s);
		i = -1;
		while (++i < len)
			s[i] = ft_tolower((int)s[i]);
		return (s);
	}
	return (NULL);
}
