/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:52:57 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/10 02:55:08 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char			*ft_strinit(char **s)
{
	if (s == NULL || (*s = ft_strnew(0)) == NULL)
		return (NULL);
	return (*s);
}
