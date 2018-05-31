/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:06:56 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lst_remove_if(t_list **begin_list, void *content, int (*cmp)())
{
	t_list *tmp;
	t_list *prev;

	tmp = *begin_list;
	prev = NULL;
	while (!cmp(tmp->content, content) && tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (cmp(tmp->content, content))
	{
		if (prev)
			prev->next = tmp->next;
		else
			*begin_list = tmp->next;
		ft_lstdelone(&tmp, &ft_lst_clear);
	}
}
