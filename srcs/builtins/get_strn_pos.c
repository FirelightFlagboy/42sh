/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strn_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:54:44 by ybensimo          #+#    #+#             */
/*   Updated: 2018/04/23 16:31:56 by ybensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int		get_strn_pos(char **str, char *val, int n)
{
	int		i;

	i = 0;
	while (str[i] && ft_strncmp(str[i], val, n))
		i++;
	return (i);
}
