/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:02:53 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/08 09:15:30 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					ft_eval_cmd(t_ast *ast)
{
	int		rt;
	char	**argv;

	if ((rt = ft_get_argv(&argv, ast->node_tokens, ast->size_tab)) == -1)
		return (ft_warnx("build argv", "malloc error"));
	if (argv == NULL || rt <= 0)
	{
		ft_dprintf(2, "42sh : %s : command not found\n",
		ast->node_tokens[0].value);
		if (argv)
			ft_free_tchar(argv);
		return (1);
	}
	if (gtsh(0)->debug & 0b10)
		ft_print_argv(argv);
	if (ft_strchr(argv[0], '/'))
		return (ft_eval_direct_cmd(argv, ast));
	else if (ft_eval_built(argv, &rt, ast))
		return (rt);
	else
		return (ft_eval_hash(argv, ast));
	return (1);
}

static inline int	ft_eval_ctrl(t_ast *a, int type)
{
	if (PIPE_OP == type)
		return (ft_eval_pipe(a));
	if (OR_OP == type)
	{
		return ((ft_eval_ast(a->left_son) == 0\
		|| ft_eval_ast(a->right_son) == 0) ? 0 : 1);
	}
	if (AND_OP == type)
	{
		return ((ft_eval_ast(a->left_son) == 0\
		&& ft_eval_ast(a->right_son) == 0) ? 0 : 1);
	}
	if (SEMI_COLON_OP == type || BACKGROUND_OP == type)
	{
		ft_eval_ast(a->left_son);
		return (ft_eval_ast(a->right_son));
	}
	return (0);
}

int					ft_eval_ast(t_ast *ast)
{
	int		type;

	if (ast == NULL)
		return (0);
	type = ast->node_tokens[0].family;
	if (type == WORD)
		return (ft_eval_cmd(ast));
	else if (type == OP_CTRL)
		return (ft_eval_ctrl(ast, ast->node_tokens[0].name));
	return (0);
}
