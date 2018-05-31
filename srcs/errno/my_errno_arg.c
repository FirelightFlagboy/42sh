/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errno_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 10:08:14 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/25 10:27:59 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_errno.h"

int		ft_bad_option(char *s, char c)
{
	ft_dprintf(2, "%s : illegal option -- %c\n", s, c);
	return (EXIT_FAILURE);
}

int		ft_usage(char *name, char *usage)
{
	ft_dprintf(2, "usage: %s %s\n", name, usage);
	return (EXIT_FAILURE);
}
