/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_justified_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:19:02 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_justified_str(char *str, size_t tot_size, char fill,\
		t_bool right)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(str);
	if (!right)
		ft_putstr(str);
	while (i < (tot_size - len))
	{
		ft_putchar(fill);
		i++;
	}
	if (right)
		ft_putstr(str);
}
