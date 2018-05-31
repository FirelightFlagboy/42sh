/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errno_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:27:04 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/01 15:03:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_errno.h"

size_t		ft_strlen_err(char const *s)
{
	char *d;

	d = (char*)s;
	while (*d)
		d++;
	return (d - s);
}

char		*ft_strcpy_warnx(char *d, char const *s, size_t lim)
{
	size_t	len;
	size_t	i;

	if (d == NULL || s == NULL)
	{
		g_errn = ERR_FAULT;
		return (NULL);
	}
	len = ft_strlen_err(s);
	if (len > lim)
	{
		g_errn = ERR_NAMETOOLONG;
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
	return (d);
}

char		*ft_strcat_warnx(char *d, char const *s, size_t lim)
{
	size_t	lend;
	size_t	lens;
	size_t	i;

	if (d == NULL || s == NULL)
	{
		g_errn = ERR_FAULT;
		return (NULL);
	}
	lend = ft_strlen_err(d);
	lens = ft_strlen_err(s);
	if (lend + lens > lim)
	{
		g_errn = ERR_NAMETOOLONG;
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		d[i + lend] = s[i];
		i++;
	}
	d[i + lend] = 0;
	return (d);
}
