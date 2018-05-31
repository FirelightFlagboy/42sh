/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errno_warnx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:59:38 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/28 15:59:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_errno.h"

int		ft_warnx(char *cmd, char *error_type)
{
	ft_dprintf(2, "%s\e[0m : %s\e[0m\n", cmd, error_type);
	return (EXIT_FAILURE);
}

int		ft_warnx_errn(char *type, int errnum)
{
	if (ft_iscritical(errnum))
		return (ft_error_errn(type, errnum));
	ft_dprintf(2, "%s\e[0m : %s\e[0m\n", type, ft_strerror(errnum));
	return (EXIT_WARNING);
}

int		ft_warnx_sig(char *type, int st)
{
	ft_dprintf(2, "%s\e[0m : %s\e[0m\n", type, ft_strsignal(st));
	return (EXIT_WARNING);
}

int		ft_warn2_errn(char *type, char *s, int errnum)
{
	if (ft_iscritical(errnum))
		return (ft_error_errn(type, errnum));
	ft_dprintf(2, "%s\e[0m : %s\e[0m : %s\n", type, s, ft_strerror(errnum));
	return (EXIT_WARNING);
}
