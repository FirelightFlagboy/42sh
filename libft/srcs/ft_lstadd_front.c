/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 01:14:52 by anonymous          #+#    #+#             */
/*   Updated: 2016/12/31 00:32:10 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
** void ft_lstadd_front(t_list **alst, t_list *new);
**
** DESCRIPTION
**	Add the `new' element at the beginning of the `l' list.
**	Do nothing if `new' or `l' is NULL.
** PARAM. #1 - `l'
**	The address of a pointer of the first element of a list.
** PARAM. #2
**	The element to add at the beginning.
** RETURN
**	Nothing.
*/

void	ft_lstadd_front(t_list **l, t_list *new)
{
	if (new == NULL || l == NULL)
		return ;
	new->next = *l;
	*l = new;
}
