/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 01:45:21 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/03 11:03:48 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			print_env(t_envl *env_list)
{
	while (env_list)
	{
		if (env_list->value)
		{
			ft_printf("\033[1;36m%s\033[0m=%s\n",\
			env_list->name, env_list->value);
		}
		env_list = env_list->next;
	}
}

static t_env_s	*create_env_struct(char **cmd)
{
	t_env_s *env_s;

	env_s = NULL;
	if ((env_s = (t_env_s *)malloc(sizeof(t_env_s))))
	{
		env_s->set = op_setenv(cmd);
		env_s->ignore = op_ignore(cmd);
		env_s->cmd = op_cmd(cmd);
	}
	return (env_s);
}

static void		set_error_flag(t_sh **sh, t_env_s *env_s, int *ret)
{
	if (env_s->unset == -1 && (*ret = 1))
		ft_putendl_fd("env: option requires an argument -- 'u'", 2);
	else if (env_s->null == 1 && env_s->cmd == 1 && (*ret = 1))
		ft_putendl_fd("env: cannot specify --null (-0) with command", 2);
	if (*ret)
	{
		((*sh)->ret = -1);
		g_exit = -1;
	}
}

int				has_errors(t_sh **sh, t_env_s *env_s, char **cmd)
{
	int	ret;
	int	bin;

	bin = 0;
	ret = 0;
	while (*cmd)
	{
		if (*cmd[0] != '-')
			bin++;
		if (bin == 2)
			break ;
		if (*cmd[0] == '-' && *(*cmd + 1) && \
				!(*(*cmd + 1) == 'i' || *(*cmd + 1) == '0' ||
				ft_strcmp(*cmd, "--null") == 0) && (ret = 1))
		{
			ft_putstr_fd("env: illegal option -- ", 2);
			ft_putchar_fd((*(*cmd + 1)), 2);
			ft_putstr_fd("\nusage: env [-i] [name=value ...] ", 2);
			ft_putendl_fd("[utility [argument ...]]", 2);
		}
		cmd++;
	}
	set_error_flag(sh, env_s, &ret);
	return (ret);
}

int				builtin_env(t_sh **sh)
{
	t_env_s	*env_s;

	(*sh)->ret = 0;
	if ((*sh)->cmd[1] == NULL)
		print_setenv((*sh)->env);
	else if ((env_s = create_env_struct((*sh)->cmd)))
	{
		if (has_errors(sh, env_s, (*sh)->cmd))
		{
			free(env_s);
			return (-1);
		}
		else if (env_s->ignore == 1 && env_s->cmd == 0 && env_s->set == 1)
			print_setenv((*sh)->cmd);
		else if (env_s->ignore == 1 && env_s->cmd == 1)
			work_as_newenv((*sh)->cmd, sh);
		else if (env_s->cmd == 1)
			work_with_alterenv((*sh)->cmd, sh);
		else if (env_s->cmd == 0)
			work_environ_and_display((*sh)->cmd, sh, env_s);
		free(env_s);
	}
	return ((*sh)->ret);
}
