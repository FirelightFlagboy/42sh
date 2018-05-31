/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 06:01:04 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:44:52 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** char *ft_strtrim(char const *s);
**
** DESCRIPTION
**	Alloue (avec malloc(3)) et retourne une copie de la chaine
**	passée en paramètre sans les espaces blancs au debut et à la
**	fin de cette chaine. On considère comme espaces blancs les
**	caractères ’ ’, ’\n’ et ’\t’. Si s ne contient pas d’espaces
**	blancs au début ou à la fin, la fonction renvoie une copie de
**	s. Si l’allocation echoue, la fonction renvoie NULL.
** Param. #1
**	La chaine de caractères à trimmer.
** Retour
**	La chaine de caractère “fraiche” trimmée ou bien une copie
**	de s sinon.
*/

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		beg;
	int		end;

	if (!s)
		return (0);
	beg = 0;
	end = 0;
	end = ft_strlen(s);
	while (s[beg]\
		&& (s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t'))
		beg++;
	while (s[end - 1]\
		&& (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t'))
		end--;
	if ((end - beg > 0)\
		&& (res = ft_strncpy(ft_strnew(end - beg), &s[beg], end - beg)))
		return (res);
	return (NULL);
}
