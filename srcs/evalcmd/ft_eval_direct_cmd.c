/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_direct_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 09:20:56 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/02 16:18:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int			ft_wait_direct_cmd(pid_t pid, char **av)
{
	int		res;

	if (waitpid(pid, &res, 0) == -1)
		return (ft_warnx("42sh", "waitpid error"));
	ft_exit_code(&res, av[0]);
	ft_free_tchar(av);
	return (res);
}

static inline int	ft_fork_direct(t_sh *sh, t_ast *ast, char **av)
{
	int		i;
	int		tfd[10];

	if (ft_redir(ast->node_tokens, ast->size_tab, tfd))
	{
		ft_close_fd(tfd);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < 10)
		ft_do_redir(tfd[i], i);
	execve(av[0], av, sh->env);
	ft_error("42sh", "execve error");
	ft_close_fd(tfd);
	exit(EXIT_FAILURE);
}

int					ft_eval_direct_cmd(char **av, t_ast *ast)
{
	int		res;
	t_sh	*sh;
	t_stat	st;

	sh = gtsh(NULL);
	res = 1;
	if (ft_access(av[0], X_OK) || (stat(av[0], &st) && (g_errn = ERR_STAT))\
	|| (!S_ISREG(st.st_mode) && (g_errn = ERR_ISNOTFILE)))
	{
		ft_warn2_errn("42sh", av[0], g_errn);
		ft_free_tchar(av);
		return (126);
	}
	if ((sh->child = fork()) == 0)
	{
		exit(ft_fork_direct(sh, ast, av));
	}
	else if (sh->child == -1)
		return (ft_warnx("42sh", "fork error"));
	return (ft_wait_direct_cmd(sh->child, av));
}
