/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:01:18 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 18:52:06 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** char	*ft_arr_to_str(char **arr)
**
** NAME
** DESCRIPTION
*/

#include "libft.h"

char	*ft_arr_to_str(char **arr)
{
	char	*res;
	char	*temp;
	int		i;

	if (!arr || !*arr)
		return (NULL);
	res = ft_strdup(arr[0]);
	i = 1;
	while (arr[i])
	{
		temp = res;
		res = ft_str3join(res, " ", arr[i]);
		ft_strdel(&temp);
		i++;
	}
	return (res);
}
