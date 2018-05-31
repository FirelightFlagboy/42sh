/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:29:45 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 14:02:07 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
** void ft_lstdel(t_list **alst, void (*del)(void *,size_t));
**
** DESCRIPTION
**	Prend en paramètre l’adresse d’un pointeur sur un maillon et
**	libère la mémoire de ce maillon et celle de tous ses successeurs
**	l’un après l’autre avec del et free(3). Pour terminer,
**	le pointeur sur le premier maillon maintenant libéré doit être
**	mis à NULL (de manière similaire à la fonction ft_memdel de
**	la partie obligatoire).
** PARAM. #1
**	L’adresse d’un pointeur sur le premier maillon d’une liste à
**	libérer.
*/

void	ft_lstdel(t_list **alst, void (*del)(void**, size_t*))
{
	t_list *next;

	while (*alst)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next;
	}
}
