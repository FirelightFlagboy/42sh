/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:50 by anonymous          #+#    #+#             */
/*   Updated: 2018/03/07 16:46:16 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Command is good
*/

static int	command_is_good(char *cmd)
{
	return (!(!cmd || ft_strisblank(cmd)));
}

/*
** validate command
** trim
** handle exclamation expansion
*/

int			validate_and_prep_cmd(t_sh **sh)
{
	char *tmp;

	if (command_is_good((*sh)->buff))
	{
		tmp = (*sh)->buff;
		(*sh)->buff = ft_strtrim((*sh)->buff);
		if (ft_strstr((*sh)->buff, "!!") &&
			replace_double_exclamation(sh, tmp))
		{
			ft_strdel(&tmp);
			return (-1);
		}
		ft_strdel(&tmp);
		if (ft_strchr((*sh)->buff, '!') &&
		(replace_single_exclamation(&(*sh)->buff) == -1))
			return (-1);
		return (0);
	}
	return (-1);
}
