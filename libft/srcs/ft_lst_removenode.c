/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_removenode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:07:16 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lst_removenode(t_list **begin_list, t_list *removable)
{
	t_list	*next;

	if (begin_list && *begin_list && removable)
	{
		if (*begin_list == removable)
		{
			next = (*begin_list)->next;
			ft_lstdelone(begin_list, &ft_lst_clear);
			*begin_list = next;
		}
		else
			ft_lst_removenode(&((*begin_list)->next), removable);
	}
}
