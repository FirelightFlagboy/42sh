/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_built.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 09:40:33 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/05 09:11:08 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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
	dup2(sh->basic_fd[STDIN_FILENO], STDIN_FILENO);
	dup2(sh->basic_fd[STDOUT_FILENO], STDOUT_FILENO);
	dup2(sh->basic_fd[STDERR_FILENO], STDERR_FILENO);
	ft_free_tchar(av);
	return (r);
}

int					ft_eval_built(char **av, int *rt, t_ast *ast)
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

	*rt = 0;
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
