/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_create_leafs_and_nodes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:12:00 by eduriez           #+#    #+#             */
/*   Updated: 2018/05/04 11:12:05 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

static t_ast	*ft_create_ast_node(t_token *tab_tokens, const int size_tab)
{
	t_ast *new_node;

	new_node = (t_ast*)ft_memalloc(sizeof(t_ast));
	if (new_node == NULL)
		return (NULL);
	new_node->node_tokens = tab_tokens;
	new_node->size_tab = size_tab;
	new_node->left_son = NULL;
	new_node->right_son = NULL;
	return (new_node);
}

int				ft_create_new_leaf(t_token_list *start_parsing,
									t_token_list *current_operator,
									t_ast **ast)
{
	t_token	*leaf_content;
	int		cmd_len;

	cmd_len = ft_cmdlen(start_parsing, current_operator);
	if (cmd_len == 0)
		return (1);
	else
	{
		leaf_content = ft_get_leaf_content(start_parsing, cmd_len);
		if (leaf_content == NULL)
			return (0);
		*ast = ft_create_ast_node(leaf_content, cmd_len);
	}
	if (*ast == NULL)
	{
		ft_memdel((void**)&leaf_content);
		return (0);
	}
	return (1);
}

int				ft_create_new_node(t_ast **ast, t_token_list *current_operator)
{
	t_token	*node_content;
	char	*value;

	node_content = (t_token*)ft_memalloc(sizeof(t_token));
	if (node_content == NULL)
		return (0);
	value = ft_strdup(current_operator->token.value);
	if (value == NULL)
	{
		ft_memdel((void**)&node_content);
		return (0);
	}
	*node_content = ft_create_token(current_operator->token.family,
	current_operator->token.name, value);
	*ast = ft_create_ast_node(node_content, 1);
	if (*ast == NULL)
	{
		ft_memdel((void**)&(node_content->value));
		ft_memdel((void**)&node_content);
		return (0);
	}
	return (1);
}
