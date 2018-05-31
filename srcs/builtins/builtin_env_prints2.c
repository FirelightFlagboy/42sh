/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_prints2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 03:29:28 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/03 11:06:55 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		compare_and_del(char ***sh_env, char **new, int x, int *y)
{
	char	*tmp_env;
	char	*tmp_new;

	tmp_env = ft_strndup((*sh_env)[*y],\
				ft_strlen_until((*sh_env)[*y], '='));
	tmp_new = ft_strndup(new[x], ft_strlen_until(new[x], '='));
	if (ft_strcmp(tmp_env, tmp_new) == 0)
		*sh_env = ft_arr_del_at(*sh_env, *y);
	else
		(*y)++;
	ft_strdel(&tmp_env);
	ft_strdel(&tmp_new);
}

char		**join_envs(char **env, char **new)
{
	char	**joint;
	char	**sh_env;
	int		x;
	int		y;

	x = 0;
	if (!(sh_env = ft_str2dup(env)))
		return (NULL);
	while (new[x])
	{
		y = 0;
		while (sh_env[y])
			compare_and_del(&sh_env, new, x, &y);
		x++;
	}
	if (!(joint = ft_str2join(sh_env, new)))
		malloc_error();
	ft_str2del(&sh_env);
	return (joint);
}

char		**remove_duplicate_envs(char **env)
{
	char	*tmp_x;
	char	*tmp_y;
	int		x;
	int		y;

	x = -1;
	while (env[++x])
	{
		tmp_x = ft_strndup(env[x], ft_strlen_until(env[x], '='));
		y = 0;
		while (env[x + ++y])
		{
			tmp_y = ft_strndup(env[x + y], ft_strlen_until(env[x + y], '='));
			if (ft_strcmp(tmp_x, tmp_y) == 0)
			{
				env = ft_arr_del_at(env, x--);
				ft_strdel(&tmp_y);
				break ;
			}
			ft_strdel(&tmp_y);
		}
		ft_strdel(&tmp_x);
	}
	return (env);
}

void		execute_further(t_sh **sh, char **cmd, char ***env)
{
	char		**tmp_env;
	char		**ptr;
	char		*commands;
	char		**cmd_tmp;
	t_envl		*envl_list;

	ptr = get_command(cmd);
	cmd_tmp = (*sh)->cmd;
	commands = ft_arr_to_str(ptr);
	tmp_env = (*sh)->env;
	(*sh)->env = *env;
	(*sh)->cmd = ft_splittreat(commands, ' ');
	envl_list = (*sh)->env_list;
	(*sh)->env_list = createenv(*env);
	(*sh)->ret = ft_lauch(ptr[0], ptr, *env);
	ft_strdel(&commands);
	ft_str2del(&(*sh)->cmd);
	(*sh)->cmd = cmd_tmp;
	ft_str2del(&(*sh)->env);
	(*sh)->env = tmp_env;
	clean_env_list(&(*sh)->env_list);
	(*sh)->env_list = envl_list;
}
