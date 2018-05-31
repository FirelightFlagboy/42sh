/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 11:17:00 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/09 13:35:43 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_exit_code(int *res, char *name)
{
	int	i;

	i = 0;
	if (WIFSIGNALED(*res))
	{
		i = WTERMSIG(*res);
		*res = WTERMSIG(*res) + 128;
		if (name)
			ft_dprintf(2, "\n42sh : %s: %s\n", name, ft_strsignal(i));
	}
	else if (WIFSTOPPED(*res))
	{
		i = WSTOPSIG(*res);
		if (name)
			ft_dprintf(2, "\n42sh : %s: %s\n", name, ft_strsignal(i));
	}
	else if (WIFEXITED(*res))
		*res = WEXITSTATUS(*res);
}

static int	ft_create_here(t_ast *ast)
{
	t_token	*node;
	int		size;
	int		i;

	i = -1;
	if (ast == NULL)
		return (0);
	if (ast->node_tokens[0].family == WORD)
	{
		node = ast->node_tokens;
		size = ast->size_tab;
		while (++i < size)
			if (node[i].name == DLESS)
				ft_create_heredoc(node[i + 1].value, (intmax_t)node);
	}
	else
	{
		ft_create_here(ast->left_son);
		ft_create_here(ast->right_son);
	}
	return (0);
}

static int	ft_remove_here(t_ast *ast)
{
	t_token	*node;
	int		size;
	int		i;

	i = -1;
	if (ast == NULL)
		return (0);
	if (ast->node_tokens[0].family == WORD)
	{
		node = ast->node_tokens;
		size = ast->size_tab;
		while (++i < size)
			if (node[i].name == DLESS)
				ft_rm_heredoc((uintmax_t)node);
	}
	else
	{
		ft_remove_here(ast->left_son);
		ft_remove_here(ast->right_son);
	}
	return (0);
}

void		evalcmd(t_sh *sh)
{
	signal(SIGINT, handler_child);
	if (sh->debug & 0b1)
		ft_print_ast(sh->ast);
	ft_create_here(sh->ast);
	close(sh->ttfd);
	tcsetattr(0, 0, &sh->official);
	sh->ret = ft_eval_ast(sh->ast);
	sh->child = 0;
	ft_remove_here(sh->ast);
	ft_delete_ast(sh->ast);
	tcsetattr(0, 0, &sh->term->term);
	dup2(sh->basic_fd[STDIN_FILENO], STDIN_FILENO);
	dup2(sh->basic_fd[STDOUT_FILENO], STDOUT_FILENO);
	dup2(sh->basic_fd[STDERR_FILENO], STDERR_FILENO);
	dup2(sh->basic_fd[3], sh->ttfd);
	signal(SIGINT, fctsig);
}
