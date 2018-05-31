/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:30:17 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/04 14:45:16 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_redir_fd(int old, int new)
{
	if (old == new)
		return ;
	if (dup2(old, new) != -1)
		close(old);
	return ;
}

void	exec_child(t_ast *ast, int pfd[2], int stdout)
{
	int		rt;

	dup2(pfd[1], 1);
	close(pfd[0]);
	rt = ft_eval_cmd_no_fork(ast);
	dup2(stdout, 1);
	close(stdout);
	exit(rt);
}

void	exec_parent(t_ast *ast, int pfd[2], int stdin)
{
	int rt;

	dup2(pfd[0], 0);
	close(pfd[1]);
	if (ast->node_tokens->family == WORD)
		rt = ft_eval_cmd_no_fork(ast);
	else
		rt = ft_eval_pipe(ast);
	dup2(stdin, 0);
	close(stdin);
	exit(rt);
}

int		ft_do_pipe(t_ast *ast, int pfd[2], int std[2])
{
	pid_t	left;
	pid_t	right;
	int		st_left;
	int		st_right;

	if ((left = fork()) == -1 && ft_eprintf("42sh : fork error"))
		return (close_pipe(pfd));
	else if (!left)
		exec_child(ast->left_son, pfd, std[STDOUT_FILENO]);
	if ((right = fork()) == -1 && ft_eprintf("42sh : fork error"))
		return (close_pipe(pfd));
	else if (!right)
		exec_parent(ast->right_son, pfd, std[STDIN_FILENO]);
	close(pfd[PP_READ]);
	close(pfd[PP_WRITE]);
	gtsh(NULL)->child = left;
	waitpid(right, &st_right, 0);
	waitpid(left, &st_left, 0);
	ft_exit_code(&st_right, NULL);
	return (st_right);
}

int		ft_eval_pipe(t_ast *ast)
{
	int		pfd[2];
	int		stdin;
	int		stdout;
	int		res;

	if (pipe(pfd) == -1)
	{
		ft_eprintf("42sh : pipe error");
		return (-1);
	}
	stdin = dup(STDIN_FILENO);
	stdout = dup(STDOUT_FILENO);
	res = ft_do_pipe(ast, pfd, (int[2]){stdin, stdout});
	close(stdin);
	close(stdout);
	return (res);
}
