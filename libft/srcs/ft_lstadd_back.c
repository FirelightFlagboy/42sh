/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 00:41:56 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:53:30 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** void	ft_lstadd_back(t_list **l, t_list *new);
**
** DESCRIPTION
**	Add the `new' element at the end of the `l' list.
**	Do nothing `l' is NULL
** PARAM. #1 - `l'
**	The address of a pointer of the first element of a list.
** PARAM. #2 - `new'
**	The element to add at the end.
** RETURN
**	Nothing.
*/

int	ft_lstadd_back(t_list **l, t_list *new)
{
	t_list	*lcpy;

	if (l == NULL)
		return (1);
	if (*l == NULL)
	{
		*l = new;
		return (1);
	}
	lcpy = *l;
	while ((*l)->next != NULL)
		*l = (*l)->next;
	(*l)->next = new;
	*l = lcpy;
	return (0);
}
