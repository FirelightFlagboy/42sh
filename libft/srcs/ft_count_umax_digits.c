/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_umax_digits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 18:56:09 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** int		ft_count_umax_digits(uintmax_t number)
**
** NAME
** DESCRIPTION
*/

int		ft_count_umax_digits(uintmax_t number)
{
	int c;

	if (number == 0)
		return (1);
	c = 0;
	while (number > 0)
	{
		number /= 10;
		c++;
	}
	return (c);
}
