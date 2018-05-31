/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_del_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:55:42 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 18:40:39 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arr_del_at(char **arr, int index)
{
	int		len;
	int		i;
	char	**new_arr;

	if (!arr || !(len = ft_str2len(arr)))
		return (NULL);
	i = 0;
	new_arr = ft_str2new(len - 1);
	while (i < len)
	{
		new_arr[i] = ft_strdup(arr[((i + 1) <= index) ? i : (i + 1)]);
		i++;
	}
	ft_str2del(&arr);
	return (new_arr);
}
