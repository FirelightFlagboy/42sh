/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:22:17 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/23 11:49:31 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	hanlde_cmd(t_sh **sh, char **cmd)
{
	t_envl	*tmp;
	t_envl	*prev;

	tmp = (*sh)->env_list;
	prev = NULL;
	if (!tmp)
		return ;
	while (!(ft_strcmp(tmp->name, *cmd) == 0) && tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->name, *cmd) == 0)
	{
		if (prev)
			prev->next = tmp->next;
		else
			(*sh)->env_list = tmp->next;
		ft_strdel(&(tmp->name));
		ft_strdel(&(tmp->value));
		free(tmp);
		if (ft_strcmp(*cmd, "PATH") == 0)
			ft_refresh_hash();
	}
}

int		builtin_unsetenv(t_sh **sh)
{
	char	**cmd;

	cmd = (*sh)->cmd;
	if (cmd[1] == NULL)
		return (-1);
	cmd++;
	while (*cmd)
		hanlde_cmd(sh, cmd++);
	rebuild_str2env(sh);
	return (0);
}
