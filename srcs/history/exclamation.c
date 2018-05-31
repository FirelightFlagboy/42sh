/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclamation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:23 by anonymous          #+#    #+#             */
/*   Updated: 2018/03/07 15:12:13 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Refer to the previous command. By itself, this expansion repeats the previous
** command.
*/

int		replace_double_exclamation(t_sh **sh, char *tmp)
{
	if ((*sh)->history->size > 0)
	{
		ft_str_replace(&(*sh)->buff, "!!", (*sh)->history->list->cmd, 0);
		if (ft_strcmp(tmp, (*sh)->buff) != 0)
			ft_putendl((*sh)->buff);
		return (0);
	}
	ft_putendl_fd("Error: No previous history.", 2);
	return (-1);
}
