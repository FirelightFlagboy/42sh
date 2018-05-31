/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_operators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:47:06 by eduriez           #+#    #+#             */
/*   Updated: 2018/04/19 21:47:11 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int	ft_manage_newline_operator(const char *cmd_user,
							int *op_position,
							t_token_list **list_tokens)
{
	t_token	new_token;
	int		ret;

	(void)cmd_user;
	new_token = ft_create_token(OP_CTRL, NEWLINE_OP, ft_strdup("\n"));
	if (new_token.value == NULL)
		return (0);
	ret = ft_add_token(new_token, list_tokens);
	if (!ret)
	{
		ft_memdel((void**)&(new_token.value));
		return (0);
	}
	*op_position += 1;
	return (1);
}

int	ft_manage_and_operators(const char *cmd_user,
							int *op_position,
							t_token_list **list_tokens)
{
	t_token	new_token;
	int		ret;

	if (cmd_user[*op_position + 1] != '&')
		new_token = ft_create_token(OP_CTRL, BACKGROUND_OP, ft_strdup("&"));
	else
		new_token = ft_create_token(OP_CTRL, AND_OP, ft_strdup("&&"));
	if (new_token.value == NULL)
		return (0);
	ret = ft_add_token(new_token, list_tokens);
	if (!ret)
	{
		ft_memdel((void**)&(new_token.value));
		return (0);
	}
	if (new_token.name == AND_OP)
		*op_position += 2;
	else
		*op_position += 1;
	return (1);
}

int	ft_manage_or_operators(const char *cmd_user,
						int *op_position,
						t_token_list **list_tokens)
{
	t_token	new_token;
	int		ret;

	if (cmd_user[*op_position + 1] != '|')
		new_token = ft_create_token(OP_CTRL, PIPE_OP, ft_strdup("|"));
	else
		new_token = ft_create_token(OP_CTRL, OR_OP, ft_strdup("||"));
	if (new_token.value == NULL)
		return (0);
	ret = ft_add_token(new_token, list_tokens);
	if (!ret)
	{
		ft_memdel((void**)&(new_token.value));
		return (0);
	}
	if (new_token.name == PIPE_OP)
		*op_position += 1;
	else
		*op_position += 2;
	return (1);
}

int	ft_manage_semicolon_operators(const char *cmd_user,
								int *op_position,
								t_token_list **list_tokens)
{
	t_token	new_token;
	int		ret;

	if (cmd_user[*op_position + 1] == ';')
	{
		ft_putstr_fd("Lexer error : Undefined operator ';;'\n", 2);
		return (0);
	}
	new_token = ft_create_token(OP_CTRL, SEMI_COLON_OP, ft_strdup(";"));
	if (new_token.value == NULL)
		return (0);
	ret = ft_add_token(new_token, list_tokens);
	if (!ret)
	{
		ft_memdel((void**)&(new_token.value));
		return (0);
	}
	*op_position += 1;
	return (1);
}
