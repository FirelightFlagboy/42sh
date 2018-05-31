/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_inner_join.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 22:41:41 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 18:45:22 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** char	**ft_arr_inner_join(char **arr, char **arr1)
**
** NAME
** DESCRIPTION
*/

char	**ft_arr_inner_join(char **arr, char **arr1)
{
	int		n;
	char	**temp;
	char	**res;
	int		i;
	int		a;

	n = 0;
	i = 0;
	a = 0;
	temp = arr;
	while (*temp)
	{
		n += ft_arr_includes(arr1, *temp);
		temp++;
	}
	res = ft_str2new(n);
	while (a < n)
	{
		if (ft_arr_includes(arr1, arr[i]))
			res[a++] = ft_strdup(arr[i]);
		i++;
	}
	return (res);
}
