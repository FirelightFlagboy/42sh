/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:00:46 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/14 17:39:54 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

/*
** void * ft_memalloc(size_t size);
**
** DESCRIPTION
**	Alloue (avec malloc(3)) et retourne une zone de mémoire
**	“fraiche”. La mémoire allouée est initialisée à 0. Si l’allocation
**	échoue, la fonction renvoie NULL.
** Param.
**	#1 La taille de la zone de mémoire à allouer.
** Retour
**	La zone de mémoire allouée.
*/

void	*ft_memalloc(size_t size)
{
	void	*ret;

	if ((ret = (char *)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
