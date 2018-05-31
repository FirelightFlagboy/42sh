/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:22:56 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/04 14:40:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_loop_setenv(t_sh **sh, const size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	while (++i < len)
	{
		if ((s = ft_strchr((*sh)->cmd[i], '=')))
		{
			*s = 0;
			if ((*sh)->cmd[i][0])
				do_setenv(sh, (*sh)->cmd[i], s + 1);
			else
			{
				*s = '=';
				ft_eprintf("setenv : %s : missing key name\n", (*sh)->cmd[i]);
			}
		}
		else
			ft_eprintf("setenv : %s : missing '=' in it\n", (*sh)->cmd[i]);
	}
}

/*
** set name with value in shell sh environment list
*/

int			builtin_setenv(t_sh **sh)
{
	size_t	len;

	len = ft_str2len((*sh)->cmd);
	if (len == 1)
		return (builtin_env(sh));
	ft_loop_setenv(sh, len);
	return (0);
}
