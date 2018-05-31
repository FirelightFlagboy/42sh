/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_exclamation_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:32 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/23 14:01:57 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		no_history_err(char *arg)
{
	ft_putstr_fd("No such history index: ", 2);
	ft_putendl_fd(arg, 2);
	ft_memdel((void**)&arg);
	return (1);
}

/*
** Identify the type of the expansion
** 0 str
** 1 nb
** 2 #: command typed so far
** 3 ?: arg
*/

int		single_excl_type(char *str)
{
	if (*str == '?')
		return (3);
	if (*str == '#')
		return (2);
	else if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*(str + 1))))
		return (1);
	else if (ft_isalpha(*(str)))
		return (0);
	else
		return (-1);
}
