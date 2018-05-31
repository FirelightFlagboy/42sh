/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:37:11 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/14 17:45:11 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static size_t	get_n_size(int n)
{
	size_t	siz;

	siz = 1;
	while ((n /= 10))
		siz++;
	return (siz);
}

static int		ft_abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

/*
** char *ft_itoa(int n);
**
** DESCRIPTION
**	Alloue (avec malloc(3)) et retourne une chaine de caractères
**	“fraiche” terminée par un ’\0’ représentant l’entier n passé
**	en paramètre. Les nombres négatifs doivent être gérés. Si l’allocation
**	échoue, la fonction renvoie NULL.
*/

char			*ft_itoa(int n)
{
	char	*alpha;
	size_t	n_size;

	n_size = get_n_size(n);
	if (n < 0)
		n_size++;
	if ((alpha = (char *)malloc(sizeof(char) * (n_size + 1))) == NULL)
		return (NULL);
	if (n < 0)
		*alpha = '-';
	*(alpha + n_size) = '\0';
	if (!n)
	{
		*alpha = '0';
		return (alpha);
	}
	while (n)
	{
		*(alpha + n_size-- - 1) = ft_abs((n % 10)) + '0';
		n /= 10;
	}
	return (alpha);
}
