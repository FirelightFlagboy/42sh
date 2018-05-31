/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_cmd_no_fork.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:16:59 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/05 09:11:25 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int			ft_exe_hash_no_fork(char **av, t_ast *ast, char *path)
{
	t_sh	*sh;
	t_stat	st;
	int		i;
	int		tfd[10];

	sh = gtsh(NULL);
	if (ft_access(path, X_OK) || (stat(path, &st) && (g_errn = ERR_STAT))\
	|| (!S_ISREG(st.st_mode) && (g_errn = ERR_ISNOTFILE)))
	{
		ft_warn2_errn("42sh", path, g_errn);
		ft_free_tchar(av);
		return (1);
	}
	if (ft_redir(ast->node_tokens, ast->size_tab, tfd))
		exit(!ft_close_fd(tfd));
	i = -1;
	while (++i < 10)
		ft_do_redir(tfd[i], i);
	execve(path, av, sh->env);
	ft_eprintf("42sh : %s : execve error\n", path);
	ft_close_fd(tfd);
	ft_free_tchar(av);
	exit(EXIT_FAILURE);
}

static int			ft_eval_hash_no_fork(char **av, t_ast *ast)
{
	t_hash		*node;

	node = get_hash()[ft_hashing(av[0])];
	while (node)
	{
		if (ft_strcmp(av[0], node->key) == 0)
			return (ft_exe_hash_no_fork(av, ast, node->path));
		node = node->next;
	}
	ft_refresh_hash();
	node = get_hash()[ft_hashing(av[0])];
	while (node)
	{
		if (ft_strcmp(av[0], node->key) == 0)
			return (ft_exe_hash_no_fork(av, ast, node->path));
		node = node->next;
	}
	ft_eprintf("42sh : %s : command not found\n", av[0]);
	ft_free_tchar(av);
	return (127);
}

static inline int	ft_exe_built(\
	t_ast *ast, char **av, int (*f)(t_sh **))
{
	t_sh	*sh;
	int		tfd[10];
	int		r;

	sh = gtsh(NULL);
	if (ft_redir(ast->node_tokens, ast->size_tab, tfd))
	{
		ft_close_fd(tfd);
		return (1);
	}
	r = -1;
	while (++r < 10)
		ft_do_redir(tfd[r], r);
	sh->cmd = av;
	r = f(&sh);
	ft_close_fd(tfd);
	ft_free_tchar(av);
	exit(r);
}

static int			ft_eval_built_no_fork(char **av, int *rt, t_ast *ast)
{
	const char *const	name[] = {
		"export", "echo", "cd", "env", "setenv", "exit", "unsetenv",
		"history", "set", "unset", "read", NULL
	};
	int					(*const fc[])(t_sh **) = {
		ft_export, builtin_echo, builtin_cd, builtin_env,
		builtin_setenv, builtin_exit, builtin_unsetenv,
		built_history, ft_set, ft_unset, read_main, NULL
	};
	size_t				i;

	i = -1;
	while (name[++i])
	{
		if (ft_strcmp(name[i], av[0]) == 0)
		{
			*rt = ft_exe_built(ast, av, fc[i]);
			return (1);
		}
	}
	return (0);
}

int					ft_eval_cmd_no_fork(t_ast *ast)
{
	int		rt;
	char	**av;

	if ((rt = ft_get_argv(&av, ast->node_tokens, ast->size_tab)) == -1)
		return (!!ft_eprintf("42sh : getargv : malloc error\n"));
	if (av == NULL || rt <= 0)
	{
		ft_eprintf("42sh : %s : command not found\n",\
		ast->node_tokens[0].value);
		if (av)
			ft_free_tchar(av);
		return (1);
	}
	if (ft_strchr(av[0], '/'))
		return (ft_exe_hash_no_fork(av, ast, av[0]));
	else if (ft_eval_built_no_fork(av, &rt, ast))
		return (rt);
	else
		return (ft_eval_hash_no_fork(av, ast));
	return (1);
}
