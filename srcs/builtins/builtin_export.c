/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:52:01 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/24 18:54:24 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_loop_export(t_sh **sh)
{
	char	**var;
	char	**cmd;
	int		p_option;
	int		i;

	var = NULL;
	cmd = (*sh)->cmd;
	p_option = (ft_strcmp(cmd[1], "-p") == 0);
	i = p_option + 1;
	while (cmd[i])
	{
		var = ft_strsplit(cmd[i], '=');
		do_setenv(sh, var[0], var[1]);
		if (p_option)
			ft_putendl(cmd[i]);
		i++;
	}
}

int			builtin_export(t_sh **sh)
{
	if ((*sh)->cmd[1] == NULL)
		builtin_env(sh);
	else
		ft_loop_export(sh);
	return (0);
}
