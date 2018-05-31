/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:19:56 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 12:00:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_printf(char const *format, ...)
{
	va_list ap;
	int		rt;

	if (!format)
		return (-1);
	va_start(ap, format);
	rt = ft_vfprintf(stdout, format, ap);
	va_end(ap);
	return (rt);
}

int		ft_eprintf(char const *format, ...)
{
	va_list ap;
	int		rt;

	if (!format)
		return (-1);
	va_start(ap, format);
	rt = ft_vdprintf(STDERR_FILENO, format, ap);
	va_end(ap);
	return (rt);
}

int		ft_dprintf(int fd, char const *format, ...)
{
	va_list	ap;
	int		rt;

	if (!format)
		return (-1);
	va_start(ap, format);
	rt = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (rt);
}

int		ft_fprintf(FILE *stream, char const *format, ...)
{
	va_list	ap;
	int		rt;

	if (!format)
		return (-1);
	va_start(ap, format);
	rt = ft_vfprintf(stream, format, ap);
	va_end(ap);
	return (rt);
}
