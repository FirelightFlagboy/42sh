/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:16:24 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/09 23:17:11 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

t_list	*ft_lstdelel(t_list **l, t_list *el, void (*del)(void *, size_t))
{
	t_list	*beg;
	t_list	*prev;

	prev = *l;
	beg = *l;
	while (*l != NULL && *l != el)
	{
		prev = *l;
		*l = (*l)->next;
	}
	if (*l == NULL)
		return (NULL);
	if (*l == beg)
	{
		if ((*l)->next == NULL)
		{
			ft_lstdelone(l, del);
			return (NULL);
		}
		beg = (*l)->next;
	}
	prev->next = (*l)->next;
	ft_lstdelone(l, del);
	*l = beg;
	return (prev->next);
}
