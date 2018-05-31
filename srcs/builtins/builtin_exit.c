/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:25:12 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/25 15:40:32 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	is_all_int(char *cmd)
{
	while (*cmd)
	{
		if (!ft_isdigit(*cmd))
			return (0);
		cmd++;
	}
	return (1);
}

static void	manage_return_code(t_sh **sh)
{
	int arg;

	if (!is_all_int((*sh)->cmd[1]))
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		(*sh)->ret = 1;
		g_exit = 1;
	}
	else if ((arg = ft_atoi((*sh)->cmd[1])))
	{
		(*sh)->ret = arg;
		g_exit = arg;
	}
}

int			builtin_exit(t_sh **sh)
{
	if ((*sh)->cmd[1] && (*sh)->cmd[2])
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (-1);
	}
	else if ((*sh)->cmd[1] && (*sh)->cmd[2] == NULL)
		manage_return_code(sh);
	term_trigger(sh, 1);
	ft_str2del(&((*sh)->cmd));
	tcsetattr(STDIN_FILENO, 0, &(*sh)->official);
	closesh(sh);
	exit((*sh)->ret);
}
