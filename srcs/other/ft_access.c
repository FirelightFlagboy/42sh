/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 09:25:00 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/18 10:57:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_access(char *path, int mode)
{
	if (access(path, F_OK))
	{
		g_errn = ERR_NOENT;
		return (1);
	}
	if (access(path, mode))
	{
		g_errn = ERR_ACCESS;
		return (1);
	}
	return (0);
}
