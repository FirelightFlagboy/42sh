/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:47:47 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 11:58:42 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int			ft_sprintf(char *s, char *format, ...)
{
	va_list ap;
	int		rt;

	if (!s || !format)
		return (-1);
	va_start(ap, format);
	rt = ft_vsprintf(s, format, ap);
	va_end(ap);
	return (rt);
}

int			ft_snprintf(char *s, size_t n, char *format, ...)
{
	va_list ap;
	int		rt;

	if (!s || !format)
		return (-1);
	va_start(ap, format);
	rt = ft_vsnprintf(s, n, format, ap);
	va_end(ap);
	return (rt);
}

int			ft_asprintf(char **as, char *format, ...)
{
	va_list ap;
	int		rt;

	if (!as || !format)
		return (-1);
	va_start(ap, format);
	rt = ft_vasprintf(as, format, ap);
	va_end(ap);
	return (rt);
}
