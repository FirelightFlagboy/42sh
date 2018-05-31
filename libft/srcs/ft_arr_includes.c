/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_includes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:12:48 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 18:42:57 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** int		ft_arr_includes(char **arr, char *str)
**
** NAME
** DESCRIPTION
*/

int		ft_arr_includes(char **arr, char *str)
{
	char **temp;

	temp = arr;
	while (*temp)
	{
		if (ft_strcmp(*temp, str) == 0)
			return (1);
		temp++;
	}
	return (0);
}
