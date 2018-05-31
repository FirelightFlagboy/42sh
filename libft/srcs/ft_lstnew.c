/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:48:14 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/14 17:40:30 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** t_list * ft_lstnew(void const *content, size_t content_size);
**
** DESCRIPTION
**	Alloue (avec malloc(3)) et retourne un maillon “frais”. Les
**	champs content et content_size du nouveau maillon sont
**	initialisés par copie des paramètres de la fonction. Si le paramètre
**	content est nul, le champs content est initialisé à
**	NULL et le champs content_size est initialisé à 0 quelque
**	soit la valeur du paramètre content_size. Le champ next
**	est initialisé à NULL. Si l’allocation échoue, la fonction renvoie
**	NULL.
** PARAM. #1
**	Le contenu à ajouter au nouveau maillon.
** PARAM. #2
**	La taille du contenu à ajouter au nouveau maillon.
** RETURN
**	 Le nouveau maillon.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	if ((new_elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new_elem->next = NULL;
	if ((new_elem->content = malloc(content_size)) == NULL)
	{
		free(new_elem);
		return (NULL);
	}
	if (content != NULL)
	{
		ft_memcpy(new_elem->content, content, content_size);
		new_elem->content_size = content_size;
		return (new_elem);
	}
	new_elem->content = NULL;
	new_elem->content_size = 0;
	return (new_elem);
}
