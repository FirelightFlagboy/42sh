/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errno_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:09:01 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/25 10:38:42 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_errno.h"

int		ft_error(char *cmd, char *error_type)
{
	ft_printf("%s\e[0m : %s\n", cmd, error_type);
	exit(EXIT_FAILURE);
}

int		ft_error_errn(char *type, int errnum)
{
	ft_printf("%s\e[0m : %s\n", type, ft_strerror(errnum));
	exit(EXIT_FAILURE);
}

int		ft_error2_errn(char *type, char *s, int errnum)
{
	ft_printf("%s\e[0m : %s\e[0m : %s\n", type, s, ft_strerror(errnum));
	exit(EXIT_FAILURE);
}
