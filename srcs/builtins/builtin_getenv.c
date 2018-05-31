/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_getenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 09:08:20 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 18:42:14 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_getenv(t_sh **sh)
{
	size_t	len;
	char	*val;

	len = ft_str2len((*sh)->cmd);
	if (len > 2)
	{
		ft_putendl_fd("getenv: too many arguments", 2);
		(*sh)->ret = 2;
		g_exit = 2;
		return (-1);
	}
	else if (len == 2)
	{
		if ((val = get_env_val(sh, (*sh)->cmd[1])))
			ft_putendl(val);
		else
		{
			ft_putstr_fd("getenv: env variable ", 2);
			ft_putstr_fd((*sh)->cmd[1], 2);
			ft_putendl_fd(" is not found", 2);
		}
	}
	return (0);
}
