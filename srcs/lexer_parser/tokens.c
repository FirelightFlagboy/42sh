/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:49:08 by eduriez           #+#    #+#             */
/*   Updated: 2018/05/02 12:43:06 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int				ft_cmdlen(t_token_list *begin_list, t_token_list *end_list)
{
	int	i;

	i = 0;
	while (begin_list != end_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

t_token			ft_create_token(const t_token_family family,
								const t_token_name name,
								char *value)
{
	t_token token;

	token.family = family;
	token.name = name;
	token.value = value;
	return (token);
}

int				ft_add_token(const t_token token, t_token_list **list_tokens)
{
	t_token_list	*new_elem;
	t_token_list	*begin_list;

	new_elem = (t_token_list*)ft_memalloc(sizeof(t_token_list));
	if (new_elem == NULL)
		return (0);
	new_elem->token = token;
	new_elem->next = NULL;
	begin_list = *list_tokens;
	if (*list_tokens == NULL)
		*list_tokens = new_elem;
	else
	{
		while (begin_list->next != NULL)
			begin_list = begin_list->next;
		begin_list->next = new_elem;
	}
	return (1);
}

t_token_list	*ft_find_next_operator(t_token_list *start_token)
{
	t_token_list *elem_found;

	elem_found = NULL;
	while (start_token != NULL && elem_found == NULL)
	{
		if (start_token->token.family == OP_CTRL)
			elem_found = start_token;
		else
			start_token = start_token->next;
	}
	return (elem_found);
}
