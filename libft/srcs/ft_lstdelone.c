/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:06:39 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 14:02:58 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
** void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
**
** DESCRIPTION
**	Prend en paramètre l’adresse d’un pointeur sur un maillon et
**	libère la mémoire du contenu de ce maillon avec la fonction
**	del passée en paramètre puis libère la mémoire du maillon
**	en lui même avec free(3). La mémoire du champ next ne
**	doit en aucun cas être libérée. Pour terminer, le pointeur sur
**	le maillon maintenant libéré doit être mis à NULL (de manière
**	similaire à la fonction ft_memdel de la partie obligatoire).
** PARAM. #1
**	L’adresse d’un pointeur sur le maillon à libérer.
** RETURTN
**	Rien.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void**, size_t*))
{
	if (del)
		del(&((*alst)->content), &(*alst)->content_size);
	ft_memdel((void**)alst);
}
