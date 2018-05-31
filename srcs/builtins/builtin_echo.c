/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:09:23 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 14:08:05 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	get_flag_echo(t_sh *sh, int *i)
{
	int		n;
	int		p;

	n = 1;
	while (sh->cmd[*i] && sh->cmd[*i][0] == '-')
	{
		p = 1;
		while (sh->cmd[*i][p] && sh->cmd[*i][p] == 'n')
			p++;
		if (sh->cmd[*i][p] && sh->cmd[*i][p] != 'n')
			return (n);
		else if (p > 0 && sh->cmd[*i][p - 1] == 'n')
			n = 0;
		(*i)++;
	}
	return (n);
}

int			builtin_echo(t_sh **sh)
{
	int		i;
	int		n;

	i = 1;
	n = get_flag_echo(*sh, &i);
	while ((*sh)->cmd[i])
	{
		ft_putstr((*sh)->cmd[i]);
		++i;
		((*sh)->cmd[i]) ? ft_putchar(' ') : (0);
	}
	if (n == 1)
		ft_putchar('\n');
	return (0);
}
