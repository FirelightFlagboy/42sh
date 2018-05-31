/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:46:26 by eduriez           #+#    #+#             */
/*   Updated: 2018/05/02 18:24:36 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

static int	ft_manage_pipe_op_case(t_token_list *start_left_command,
									t_token_list **current_operator,
									t_ast **pipe_node)
{
	t_token_list *start_right_command;

	start_right_command = NULL;
	if (!ft_create_new_node(pipe_node, *current_operator)
			|| !ft_create_new_leaf(start_left_command, *current_operator,
				&((*pipe_node)->left_son)))
	{
		return (0);
	}
	start_right_command = (*current_operator)->next;
	*current_operator = ft_find_next_operator((*current_operator)->next);
	if (*current_operator == NULL || (*current_operator)->token.name != PIPE_OP)
	{
		if (!ft_create_new_leaf(start_right_command, *current_operator,
					&((*pipe_node)->right_son)))
		{
			return (0);
		}
		return (1);
	}
	else
		return (ft_manage_pipe_op_case(start_right_command, current_operator,
				&((*pipe_node)->right_son)));
}

static int	ft_create_right_part(t_token_list **start_parsing,
								t_token_list **current_operator,
								t_ast **ast)
{
	*current_operator = ft_find_next_operator(*start_parsing);
	if (*current_operator == NULL || (*current_operator)->token.name != PIPE_OP)
	{
		if (!ft_create_new_leaf(*start_parsing, *current_operator,
					&((*ast)->right_son)))
		{
			return (0);
		}
	}
	else if (!ft_manage_pipe_op_case(*start_parsing, current_operator,
				&((*ast)->right_son)))
	{
		return (0);
	}
	if (*current_operator != NULL)
		*start_parsing = (*current_operator)->next;
	else
		*start_parsing = NULL;
	return (1);
}

static int	ft_create_two_sons(t_token_list **start_parsing,
							t_token_list **current_operator,
							t_ast **ast)
{
	if (!ft_create_new_leaf(*start_parsing, *current_operator,
				&((*ast)->left_son)))
	{
		return (0);
	}
	*start_parsing = (*current_operator)->next;
	return (ft_create_right_part(start_parsing, current_operator, ast));
}

static int	ft_build_ast_recursively(t_ast **global_ast,
									t_ast *current_node,
									t_token_list *start_parsing,
									t_token_list *current_operator)
{
	if (*global_ast == NULL)
	{
		*global_ast = current_node;
		if (!ft_create_two_sons(&start_parsing, &current_operator, global_ast))
			return (0);
		return (ft_to_ast(start_parsing, current_operator, global_ast));
	}
	else
	{
		current_node->left_son = *global_ast;
		*global_ast = current_node;
		if (!ft_create_right_part(&start_parsing, &current_operator,
					global_ast))
		{
			return (0);
		}
		return (ft_to_ast(start_parsing, current_operator, global_ast));
	}
}

int			ft_to_ast(t_token_list *start_parsing,
						t_token_list *current_operator,
						t_ast **ast)
{
	t_ast			*current_node;

	current_node = NULL;
	if (current_operator == NULL)
		return (ft_create_new_leaf(start_parsing, current_operator, ast));
	else
	{
		if (!ft_create_new_node(&current_node, current_operator))
			return (0);
		return (ft_build_ast_recursively(ast, current_node, start_parsing,
					current_operator));
	}
}
