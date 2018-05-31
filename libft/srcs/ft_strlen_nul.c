/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_nul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 02:27:36 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/06 02:28:09 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen_nul(const char *s)
{
	const char	*end;

	if (s == NULL)
		return (0);
	end = s;
	while (*end++ != '\0')
		continue ;
	return (end - s - 1);
}
