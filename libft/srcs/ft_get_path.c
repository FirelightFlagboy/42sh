/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 18:58:18 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** char		*ft_get_path(char *folder_name)
**
** NAME
** DESCRIPTION
*/

char		*ft_get_path(char *folder_name)
{
	char	*beg;
	char	*beg_temp;
	char	*temp;

	temp = NULL;
	beg = ft_strdup(folder_name);
	beg_temp = beg;
	while (*beg_temp != '\0')
	{
		if (*beg_temp == '/')
			temp = beg_temp;
		beg_temp++;
	}
	if (temp)
		*temp = '\0';
	else
	{
		free(beg);
		return (ft_strdup("."));
	}
	return (beg);
}
