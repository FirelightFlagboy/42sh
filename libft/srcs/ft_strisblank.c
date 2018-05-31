/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisblank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 06:01:04 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:20:14 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisblank(char *str)
{
	while (*str)
	{
		if (((int)(*str) == 9) || ft_isspace(*str))
			str++;
		else
			return (0);
	}
	return (1);
}
