/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_exe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:39:19 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/05 09:11:46 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_exec_builtin(t_builtin_func fc, char **env, char **av, int *rt)
{
	char	**save_ev;
	t_sh	*sh;

	sh = gtsh(NULL);
	save_ev = sh->env;
	sh->env = env;
	sh->cmd = av;
	*rt = fc(&sh);
	sh->env = save_ev;
	return (1);
}

int			ft_lauch_direct(char *path, char **av, char **env)
{
	t_stat	st;

	if (ft_access(path, X_OK) || (stat(path, &st) && (g_errn = ERR_STAT))\
	|| (!S_ISREG(st.st_mode) && (g_errn = ERR_ISNOTFILE)))
	{
		ft_warn2_errn("42sh", path, g_errn);
		return (1);
	}
	execve(path, av, env);
	ft_eprintf("42sh : execve error\n");
	exit(EXIT_FAILURE);
}

int			ft_lauch_hash(char *name, char **av, char **env)
{
	t_hash *node;

	node = get_hash()[ft_hashing(name)];
	while (node)
	{
		if (ft_strcmp(name, node->key) == 0)
			return (ft_lauch_direct(node->path, av, env));
		node = node->next;
	}
	ft_eprintf("42sh : %s : command not found\n", name);
	exit(EXIT_FAILURE);
}

int			ft_build(char *path, char **av, char **env, int *rt)
{
	int					i;
	const char *const	name[] = {
		"export", "echo", "cd", "env", "setenv", "exit", "unsetenv",
		"history", "set", "unset", "read", NULL
	};
	int					(*const fc[])(t_sh **) = {
		ft_export, builtin_echo, builtin_cd, builtin_env,
		builtin_setenv, builtin_exit, builtin_unsetenv,
		built_history, ft_set, ft_unset, read_main, NULL
	};

	i = -1;
	while (name[++i])
		if (ft_strcmp(path, name[i]) == 0)
		{
			return (ft_exec_builtin(fc[i], env, av, rt));
		}
	return (0);
}

int			ft_lauch(char *path, char **av, char **env)
{
	pid_t	pid;

	if ((pid = fork()) == 0)
	{
		if (ft_strchr(path, '/'))
			exit(ft_lauch_direct(path, av, env));
		if (ft_build(path, av, env, &pid))
			exit(pid);
		exit(ft_lauch_hash(path, av, env));
		exit(EXIT_FAILURE);
	}
	else if (pid == -1)
		return (!!ft_eprintf("42sh : env : fork error\n"));
	if (waitpid(pid, &pid, 0) == -1)
		return (!!ft_eprintf("42sh : env : waitpid error\n"));
	ft_exit_code(&pid, av[0]);
	return (pid);
}
