/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:01:22 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 17:47:23 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		fix_path_if_going_home(t_sh **sh)
{
	char	**cmd;
	char	*tmp;
	char	*home;

	cmd = (*sh)->cmd;
	while (*cmd)
	{
		if (*cmd[0] == '~')
		{
			tmp = *cmd;
			home = get_env_val(sh, "HOME");
			*cmd = ft_strjoin(home, (*cmd + 1));
			ft_strdel(&tmp);
			if (!home)
			{
				ft_putendl_fd("error: no HOME env variable set", 2);
				return (-1);
			}
		}
		cmd++;
	}
	return (0);
}

void	set_env_var(t_sh **sh)
{
	char	*rdr;

	if ((rdr = ft_strnew(BUFF_SIZE)))
	{
		do_setenv(sh, "PWD", getcwd(rdr, BUFF_SIZE));
		ft_strdel(&rdr);
	}
}

int		builtin_cd(t_sh **sh)
{
	if (!(get_env_val(sh, "PWD")))
		set_env_var(sh);
	if ((prep_and_change(sh) == -1))
		return (-1);
	rebuild_str2env(sh);
	return (0);
}
