/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isescaped.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 18:59:54 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isescaped(char const *str, size_t index)
{
	int count;

	count = 0;
	if (index <= 0 || index >= ft_strlen(str))
		return (0);
	if (str[index - 1] != '\\')
		return (0);
	--index;
	while (str[index] && str[index] == '\\')
	{
		++count;
		--index;
	}
	if (count % 2 == 0)
		return (0);
	return (1);
}
