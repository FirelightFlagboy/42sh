/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenschr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 00:28:39 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/06 00:38:32 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lens	ft_strlenschr(const char *s, char c)
{
	t_lens		lens;
	const char	*start;

	start = s;
	while (*s != '\0' && *s != c)
		s++;
	lens.a = (s - start);
	if (*s == c && c != '\0')
		s++;
	start = s;
	while (*s != '\0')
		s++;
	lens.b = (s - start);
	return (lens);
}
