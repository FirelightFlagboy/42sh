/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_user_to_ast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:46:51 by eduriez           #+#    #+#             */
/*   Updated: 2018/05/03 11:19:34 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"
#include "sh.h"

t_ast		*ft_get_ast(const char *cmd_user)
{
	t_token_list	*list_tokens;
	t_ast			*ast;
	t_token_list	*first_operator;

	ast = NULL;
	first_operator = NULL;
	list_tokens = ft_lex_cmd(cmd_user);
	if (list_tokens == NULL)
		return (NULL);
	if (!ft_is_valid_cmd(list_tokens))
	{
		ft_delete_list(list_tokens);
		return (NULL);
	}
	first_operator = ft_find_next_operator(list_tokens);
	if (!ft_to_ast(list_tokens, first_operator, &ast))
	{
		ft_delete_list(list_tokens);
		malloc_error();
	}
	ft_delete_list(list_tokens);
	return (ast);
}
