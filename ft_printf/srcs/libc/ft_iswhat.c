/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:56:26 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/29 16:31:55 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_isspace_printf(int c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int		ft_isdigit_printf(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_islen_flags(int c)
{
	return (c == 'h' || c == 'l' || c == 'z' || c == 'j');
}

int		ft_isalpha_printf(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int		ft_isdigit_flags_printf(int c)
{
	return (c == 'd' || c == 'i' || c == 'D');
}
