/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errno_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:53:58 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/01 15:01:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_errno.h"

static size_t	ft_len_nb_atoi(uint32_t nb)
{
	size_t	l;

	if (nb == 0)
		return (1);
	l = 0;
	while (nb)
	{
		nb /= 10;
		l++;
	}
	return (l);
}

int				ft_atoi_to_buff(uint32_t nb, char *buf)
{
	size_t	len;
	size_t	i;

	len = ft_len_nb_atoi(nb);
	i = len;
	buf[len] = 0;
	i--;
	while (i)
	{
		buf[i--] = nb % 10 + '0';
		nb /= 10;
	}
	buf[0] = nb + '0';
	return (len);
}
