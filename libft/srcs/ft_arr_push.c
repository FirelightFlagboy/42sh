/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:00:27 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 18:51:14 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** void	ft_arr_push(char ***arr, char *str)
**
** NAME
** DESCRIPTION
*/

void	ft_arr_push(char ***arr, char *str)
{
	int		len;
	char	**new_arr;
	char	**temp;
	int		i;

	if (!str)
		return ;
	len = (int)ft_str2len(*arr);
	new_arr = ft_str2new(len + 1);
	i = 0;
	while (i < len)
	{
		new_arr[i] = ft_strdup((*arr)[i]);
		i++;
	}
	new_arr[i] = ft_strdup(str);
	temp = *arr;
	*arr = new_arr;
	ft_str2del(&temp);
}
