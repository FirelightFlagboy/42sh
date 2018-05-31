/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:47:49 by eduriez           #+#    #+#             */
/*   Updated: 2018/04/19 21:47:53 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

static int	ft_check_op(t_token_list *prev, t_token_list *op)
{
	if ((op->token.name == BACKGROUND_OP && prev->token.family != WORD)
		|| (op->token.name != BACKGROUND_OP
			&& (prev->token.family != WORD || op->next == NULL
			|| op->next->token.family != WORD)))
	{
		ft_dprintf(2, "parse error near '%s'\n", op->token.value);
		return (0);
	}
	return (1);
}

static int	ft_check_grammar(t_token_list *prev, t_token_list *begin_list)
{
	int				cmd_ok;

	cmd_ok = 1;
	while (begin_list != NULL && cmd_ok)
	{
		if (begin_list->token.family != WORD
			&& begin_list->token.name != NEWLINE_OP
			&& begin_list->token.name != SEMI_COLON_OP
			&& !ft_check_op(prev, begin_list))
			cmd_ok = 0;
		else
		{
			prev = begin_list;
			begin_list = begin_list->next;
		}
	}
	return (cmd_ok);
}

int			ft_is_valid_cmd(t_token_list *begin_list)
{
	int				error;
	t_token_list	*prev;

	error = 0;
	prev = begin_list;
	while (begin_list != NULL && begin_list->token.family == WORD)
	{
		prev = begin_list;
		begin_list = begin_list->next;
	}
	if (begin_list == NULL || begin_list->token.name == NEWLINE_OP)
		return (1);
	else
		return (ft_check_grammar(prev, begin_list));
}
