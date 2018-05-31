/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_operators.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:48:47 by eduriez           #+#    #+#             */
/*   Updated: 2018/04/19 21:48:52 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int	ft_manage_less_operators(const char *cmd_user,
							int *op_position,
							t_token_list **list_tokens)
{
	t_token	new_token;
	int		ret;

	if (cmd_user[*op_position + 1] == '<')
		new_token = ft_create_token(OP_REDIR, DLESS, ft_strdup("<<"));
	else if (cmd_user[*op_position + 1] == '&')
		new_token = ft_create_token(OP_REDIR, LESS_AND, ft_strdup("<&"));
	else
		new_token = ft_create_token(OP_REDIR, LESS, ft_strdup("<"));
	if (new_token.value == NULL)
		return (0);
	ret = ft_add_token(new_token, list_tokens);
	if (!ret)
	{
		ft_memdel((void**)&(new_token.value));
		return (0);
	}
	if (new_token.name == LESS)
		*op_position += 1;
	else
		*op_position += 2;
	return (1);
}

int	ft_manage_great_operators(const char *cmd_user,
							int *op_position,
							t_token_list **list_tokens)
{
	t_token	new_token;
	int		ret;

	if (cmd_user[*op_position + 1] == '>')
		new_token = ft_create_token(OP_REDIR, DGREAT, ft_strdup(">>"));
	else if (cmd_user[*op_position + 1] == '&')
		new_token = ft_create_token(OP_REDIR, GREAT_AND, ft_strdup(">&"));
	else
		new_token = ft_create_token(OP_REDIR, GREAT, ft_strdup(">"));
	if (new_token.value == NULL)
		return (0);
	ret = ft_add_token(new_token, list_tokens);
	if (!ret)
	{
		ft_memdel((void**)&(new_token.value));
		return (0);
	}
	if (new_token.name == GREAT)
		*op_position += 1;
	else
		*op_position += 2;
	return (1);
}
