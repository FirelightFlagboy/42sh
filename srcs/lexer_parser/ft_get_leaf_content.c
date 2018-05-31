/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_leaf_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:47:28 by eduriez           #+#    #+#             */
/*   Updated: 2018/05/02 19:46:28 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

static t_token	ft_dup_token(const t_token token, int *dup_ok)
{
	t_token	dup_token;
	char	*value;

	value = ft_strdup(token.value);
	if (value == NULL)
	{
		*dup_ok = 0;
		dup_token.value = NULL;
		return (dup_token);
	}
	*dup_ok = 1;
	dup_token = ft_create_token(token.family, token.name, value);
	return (dup_token);
}

static void		ft_free_tab(t_token *tab_tokens)
{
	int	i;

	i = 0;
	while (tab_tokens[i].value != NULL)
	{
		ft_memdel((void**)&(tab_tokens[i].value));
		i++;
	}
	ft_memdel((void**)&tab_tokens);
}

static t_token	*ft_dup_cmd(t_token_list *begin_cmd,
							t_token *tab_tokens,
							const int size_tab)
{
	int		i;
	int		dup_ok;

	i = 0;
	dup_ok = 1;
	while (i < size_tab && dup_ok)
	{
		tab_tokens[i] = ft_dup_token(begin_cmd->token, &dup_ok);
		if (dup_ok)
		{
			i++;
			begin_cmd = begin_cmd->next;
		}
	}
	if (!dup_ok)
	{
		ft_free_tab(tab_tokens);
		return (NULL);
	}
	return (tab_tokens);
}

t_token			*ft_get_leaf_content(t_token_list *begin_cmd,
											const int size_tab)
{
	t_token *tab_tokens;

	tab_tokens = (t_token*)ft_memalloc(size_tab * sizeof(t_token));
	if (tab_tokens == NULL)
		return (NULL);
	else
		return (ft_dup_cmd(begin_cmd, tab_tokens, size_tab));
}
