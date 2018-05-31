/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrmif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:08:46 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstrmif(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr;
	t_list	*prev;

	prev = NULL;
	curr = *begin_list;
	while (curr != NULL)
	{
		if (!(*cmp)(curr->content, data_ref))
		{
			if (prev == NULL)
				*begin_list = curr->next;
			else
				prev->next = curr->next;
			free(curr);
		}
		prev = curr;
		curr = curr->next;
	}
}
