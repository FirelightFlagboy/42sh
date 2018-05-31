/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:32:53 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 16:38:53 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	try_up(t_sh **sh)
{
	int tc;
	int tin;

	tc = (*sh)->term->tc_len;
	tin = (*sh)->term->tc_in;
	while (tin + (*sh)->term->prompt_len >= ft_linesize())
	{
		ft_putstr(tgetstr("up", NULL));
		tin -= ft_linesize();
	}
}
