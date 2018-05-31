/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:48:38 by eduriez           #+#    #+#             */
/*   Updated: 2018/05/11 09:40:18 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

static int		ft_lex_word(const char *cmd_user, int *end_pos_word)
{
	int	lexing_ok;

	lexing_ok = 1;
	while (!ft_is_start_op(cmd_user[*end_pos_word])
			&& !ft_isspace_separator(cmd_user[*end_pos_word])
			&& cmd_user[*end_pos_word] != '\0' && lexing_ok)
	{
		if (cmd_user[*end_pos_word] == '\'' || cmd_user[*end_pos_word] == '"')
			lexing_ok = ft_lex_quotes(cmd_user, end_pos_word);
		else if (cmd_user[*end_pos_word] == '\\'
				&& cmd_user[*end_pos_word + 1] != '\0')
			*end_pos_word += 2;
		else
			*end_pos_word += 1;
	}
	return (lexing_ok);
}

static int		ft_tokenize_word(const char *cmd_user,
								const int start_word,
								const int end_word,
								t_token_list **list_tokens)
{
	t_token new_token;
	char	*value_token;

	value_token = ft_strsub(cmd_user, start_word, end_word - start_word);
	if (value_token == NULL)
		return (0);
	if (cmd_user[end_word] == '<' || cmd_user[end_word] == '>')
	{
		if (ft_is_ionumber(value_token))
			new_token = ft_create_token(WORD, IO_NUMBER, value_token);
		else
			new_token = ft_create_token(WORD, NORMAL_WORD, value_token);
	}
	else
		new_token = ft_create_token(WORD, NORMAL_WORD, value_token);
	if (!ft_add_token(new_token, list_tokens))
	{
		ft_memdel((void**)&(new_token.value));
		return (0);
	}
	return (1);
}

int				ft_process_word(const char *cmd_user,
								int *i,
								t_token_list **list_tokens)
{
	int	start_word;
	int	ret;

	start_word = *i;
	if (ft_lex_word(cmd_user, i))
	{
		ret = ft_tokenize_word(cmd_user, start_word, *i, list_tokens);
		return (ret);
	}
	return (0);
}

t_token_list	*ft_lex_cmd(const char *cmd_user)
{
	int					i;
	int					lexing_ok;
	t_token_list		*list_tokens;
	t_lex_word_func		lex_word_func;

	i = 0;
	lexing_ok = 1;
	list_tokens = NULL;
	while (ft_isspace_separator(cmd_user[i]))
		i++;
	while (cmd_user[i] != '\0' && lexing_ok)
	{
		lex_word_func = ft_get_lex_word_function(cmd_user[i]);
		lexing_ok = lex_word_func(cmd_user, &i, &list_tokens);
		if (lexing_ok)
		{
			while (ft_isspace_separator(cmd_user[i]))
				i++;
		}
	}
	if (lexing_ok)
		return (list_tokens);
	ft_delete_list(list_tokens);
	return (NULL);
}

int				ft_lex_quotes(const char *start_quote, int *nb_chars_in_word)
{
	if (start_quote[*nb_chars_in_word] == '"')
		return (ft_lex_double_quotes(start_quote, nb_chars_in_word));
	else
		return (ft_lex_simple_quotes(start_quote, nb_chars_in_word));
}
