/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:32:36 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/23 15:18:01 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					big_enough(t_c_tab *list)
{
	size_t	largest;
	size_t	l;

	largest = 0;
	while (list)
	{
		if (largest < (l = ft_strlen(list->name)))
			largest = l;
		list = list->next;
	}
	return ((size_t)ft_linesize() > largest);
}

struct s_pad		get_largest(struct s_pad pad, t_c_tab *list)
{
	size_t	largest;
	size_t	l;

	largest = 0;
	while (list)
	{
		if (largest < (l = ft_strlen(list->name)))
			largest = l;
		list = list->next;
	}
	pad.largest = largest + 1;
	return (pad);
}
