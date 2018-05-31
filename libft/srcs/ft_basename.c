/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:02:35 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 18:53:21 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** char		*ft_basename(char *folder_name)
**
** NAME
** DESCRIPTION
*/

#include "libft.h"

char		*ft_basename(char *folder_name)
{
	char		*beg;

	if (ft_strequ(folder_name, "/"))
		return (folder_name);
	beg = ft_strchr(folder_name, '\0');
	while (beg > folder_name && *(beg - 1) != '/')
		beg--;
	return (beg);
}
