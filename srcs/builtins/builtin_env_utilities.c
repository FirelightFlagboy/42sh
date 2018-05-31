/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 05:29:52 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 16:23:08 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		op_setenv(char **cmd)
{
	int i;

	i = 1;
	while (cmd[i])
	{
		if (i == 1 && is_setenv(cmd[i]))
			return (1);
		else if (ft_strcmp("-u", cmd[i - 1]) != 0 && is_setenv(cmd[i]))
			return (1);
		i++;
	}
	return (0);
}

int		op_ignore(char **cmd)
{
	int i;

	i = 1;
	while (cmd[i])
	{
		if (i == 1 && is_ignore(cmd[i]))
			return (1);
		else if (is_setenv(cmd[i]))
			return (0);
		else if (ft_strcmp("-u", cmd[i - 1]) != 0 &&
				is_ignore(cmd[i]))
			return (1);
		i++;
	}
	return (0);
}

int		op_cmd(char **cmd)
{
	int i;
	int set;

	i = 1;
	set = 0;
	while (cmd[i])
	{
		if (set == 0 && ft_strcmp(cmd[i], "-u") == 0 && cmd[i + 1])
			i += 2;
		else if (set == 0 && (is_ignore(cmd[i])))
			i++;
		else if (is_setenv(cmd[i]))
		{
			i++;
			set = 1;
		}
		else
			return (1);
	}
	return (0);
}
