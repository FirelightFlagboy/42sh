/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:18:11 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/05 19:18:22 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strtoend(char **s)
{
	char	*start;

	if (s == NULL || *s == NULL)
		return (NULL);
	start = *s;
	while (**s != '\0')
		(*s)++;
	return (start);
}
