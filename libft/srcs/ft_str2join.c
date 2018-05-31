/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:36:53 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_str2join(char **s1, char **s2)
{
	size_t	size1;
	size_t	size2;
	char	**new;
	int		i;
	int		a;

	i = 0;
	a = 0;
	size1 = ft_str2len(s1);
	size2 = ft_str2len(s2);
	new = ft_str2new(size1 + size2);
	while (s1 && s1[a])
	{
		new[i] = ft_strdup(s1[a]);
		i++;
		a++;
	}
	a = 0;
	while (s2 && s2[a])
	{
		new[i] = ft_strdup(s2[a]);
		i++;
		a++;
	}
	return (new);
}
