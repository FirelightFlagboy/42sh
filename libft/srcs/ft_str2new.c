/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:38:47 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_str2new(size_t size)
{
	char	**str;
	size_t	i;

	i = 0;
	if (!(str = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	str[size] = 0;
	while (i < size)
		str[i++] = NULL;
	return (str);
}
