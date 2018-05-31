/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 23:10:49 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/25 13:08:51 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** clear terminal
*/

#include "sh.h"

int		uninitialize(void)
{
	ft_putstr(tgetstr("cl", NULL));
	ft_putstr("\r");
	return (0);
}
