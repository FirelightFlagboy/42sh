/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinquotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:00:41 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinquotes(char const *cmd, int pos)
{
	int i;
	int type;

	i = 0;
	type = 0;
	while (i < pos)
	{
		if (ft_isquotes(cmd[i]) && cmd[i - 1] != '\\')
		{
			if (cmd[i] == '\"')
				type = 1;
			else if (cmd[i] == '`')
				type = 2;
			else
				type = 3;
			i = ft_endquo(cmd, i);
			if (i > pos)
				return (type);
		}
		++i;
	}
	return (0);
}
