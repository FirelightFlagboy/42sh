/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splittreat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:20 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 16:43:20 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	**ft_splittreat(char *cmd, char c)
{
	char	**array;
	char	*tmp;
	int		i;

	array = ft_splitquotes(cmd, c);
	i = 0;
	while (array[i])
	{
		tmp = treat_quotes(array[i]);
		ft_strdel(&array[i]);
		array[i] = tmp;
		++i;
	}
	return (array);
}
