/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsnewcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:47:19 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/03 16:03:48 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

/*
** char	*ft_strsnewcat(int n, ...);
**
** It is the responsibility of the caller to free the memory when it is
** no longer needed
*/

char	*ft_strsnewcat(size_t n, ...)
{
	va_list	args;
	char	*s;
	char	*tmp;

	s = NULL;
	va_start(args, n);
	if (n)
	{
		s = ft_strdup(va_arg(args, char *));
		n--;
	}
	while (n)
	{
		tmp = ft_strnewcat(s, va_arg(args, char *));
		free(s);
		s = tmp;
		n--;
	}
	va_end(args);
	return (s);
}
