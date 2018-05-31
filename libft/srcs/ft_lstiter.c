/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:55:01 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/14 13:07:11 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
**
** DESCRIPTION
**	Parcourt la liste lst en appliquant à chaque maillon la fonction f.
** PARAM. #1
**	Pointeur sur le premier maillon d’une liste.
** PARAM. #2
**	L’adresse d’une fonction à laquelle appliquer chaque maillon
**	de la liste.
** RETURN
**	Void.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (f != NULL)
		while (lst != NULL)
		{
			f(lst);
			lst = lst->next;
		}
}
