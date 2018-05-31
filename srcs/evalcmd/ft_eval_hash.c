/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 09:20:48 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/02 16:18:49 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static inline int	ft_wait_hash(char **av, t_sh *sh)
{
	int		res;

	waitpid(sh->child, &res, 0);
	ft_exit_code(&res, av[0]);
	ft_free_tchar(av);
	return (res);
}

static inline int	ft_fork_hash(t_ast *ast, int tfd[10])
{
	int		i;

	if (ft_redir(ast->node_tokens, ast->size_tab, tfd))
	{
		ft_close_fd(tfd);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < 10)
		ft_do_redir(tfd[i], i);
	return (0);
}

static inline int	ft_exe_hash_pre(char *path, char **av)
{
	t_stat	st;

	if (ft_access(path, X_OK) || (stat(path, &st) && (g_errn = ERR_STAT))\
	|| (!S_ISREG(st.st_mode) && (g_errn = ERR_ISNOTFILE)))
	{
		ft_warn2_errn("42sh", path, g_errn);
		ft_free_tchar(av);
		return (126);
	}
	return (0);
}

static inline int	ft_exe_hash(char **av, t_ast *ast, char *path)
{
	int		res;
	t_sh	*sh;
	int		tfd[10];

	sh = gtsh(NULL);
	if ((res = ft_exe_hash_pre(path, av)))
		return (res);
	if ((sh->child = fork()) == 0)
	{
		ft_fork_hash(ast, tfd);
		execve(path, av, sh->env);
		ft_error("42sh", "execve error");
		ft_close_fd(tfd);
		exit(EXIT_FAILURE);
	}
	else if (sh->child == -1)
		return (ft_warnx("42sh", "fork error"));
	return (ft_wait_hash(av, sh));
}

int					ft_eval_hash(char **av, t_ast *ast)
{
	t_hash		**hash;
	t_hash		*node;
	uintmax_t	index;

	hash = get_hash();
	index = ft_hashing(av[0]);
	node = hash[index];
	while (node)
	{
		if (ft_strcmp(av[0], node->key) == 0)
			return (ft_exe_hash(av, ast, node->path));
		node = node->next;
	}
	ft_warn2_errn("42sh", av[0], (g_errn = ERR_NOCMD));
	ft_free_tchar(av);
	return (127);
}
