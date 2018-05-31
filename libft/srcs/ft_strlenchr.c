/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 00:28:07 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/06 02:14:36 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlenchr(const char *s, char c)
{
	const char	*start;

	start = s;
	while (*s != '\0' && *s != c)
		s++;
	return (s - start);
}
