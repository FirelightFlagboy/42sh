/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:22:45 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/14 17:34:59 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

/*
** t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
**
** DESCRIPTION
**	Parcourt la liste lst en appliquant à chaque maillon la fonction
**	f et crée une nouvelle liste “fraiche” avec malloc(3) ré-
**	sultant des applications successives. Si une allocation échoue,
**	la fonction renvoie NULL.
** PARAM. #1
**	Pointeur sur le premier maillon d’une liste.
** PARAM. #2
**	L’adresse d’une fonction à appliquer à chaque maillon de la
**	liste pour crér une nouvelle liste.
** RETOUR
**	La nouvelle liste.
*/

static size_t	lstlen(t_list *lst)
{
	t_list	*tmp;
	size_t	len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	new = NULL;
	tmp = NULL;
	if (f != NULL && lst != NULL
		&& (new = (t_list *)malloc(lstlen(lst) * sizeof(t_list))) != NULL)
	{
		if ((new = f(ft_lstnew(lst->content, lst->content_size))) == NULL)
			return (NULL);
		tmp = new;
		lst = lst->next;
		while (lst)
		{
			if ((tmp->next = f(ft_lstnew(lst->content, lst->content_size)))
				== NULL)
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new);
}
