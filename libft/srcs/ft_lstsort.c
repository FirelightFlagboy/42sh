/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 19:09:16 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		swap_nodes(void **one, void **two)
{
	void *tmp;

	tmp = *two;
	*two = *one;
	*one = tmp;
}

void			ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	int		sorted;

	if (!(*begin_list))
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		tmp = *begin_list;
		while (tmp->next)
		{
			if (cmp(tmp->content, tmp->next->content) > 0)
			{
				sorted = 0;
				swap_nodes(&tmp->content, &tmp->next->content);
			}
			tmp = tmp->next;
		}
	}
}
