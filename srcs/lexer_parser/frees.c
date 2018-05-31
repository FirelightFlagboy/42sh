/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:47:16 by eduriez           #+#    #+#             */
/*   Updated: 2018/04/19 21:47:21 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

void	ft_delete_list(t_token_list *list_tokens)
{
	t_token_list	*tmp;

	while (list_tokens != NULL)
	{
		tmp = list_tokens->next;
		ft_memdel((void**)&(list_tokens->token.value));
		ft_memdel((void**)&list_tokens);
		list_tokens = tmp;
	}
}

void	ft_delete_ast(t_ast *ast)
{
	int	i;

	i = 0;
	if (ast != NULL)
	{
		ft_delete_ast(ast->left_son);
		ft_delete_ast(ast->right_son);
		while (i < ast->size_tab)
		{
			ft_memdel((void**)&(ast->node_tokens[i].value));
			i++;
		}
		ft_memdel((void**)&(ast->node_tokens));
		ft_memdel((void**)&ast);
	}
}
