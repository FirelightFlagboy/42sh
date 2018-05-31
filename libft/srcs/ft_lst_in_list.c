/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_in_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:05:01 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_in_list(t_list *begin_list, void *data, int (*cmp)())
{
	while (begin_list)
	{
		if (cmp(begin_list->content, data))
			return (1);
		begin_list = begin_list->next;
	}
	return (0);
}
