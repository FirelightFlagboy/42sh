/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndelat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 06:01:04 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 15:44:06 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndelat(char *str, int index, size_t size)
{
	char	*ret;

	if (!str)
		return (NULL);
	ret = ft_strnew(ft_strlen(str) - size);
	ret = ft_strncpy(ret, str, index);
	ret[index] = *ft_strcpy(&ret[index], &str[index + (int)size]);
	return (ret);
}
