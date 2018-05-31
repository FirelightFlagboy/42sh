/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:48:27 by eduriez           #+#    #+#             */
/*   Updated: 2018/04/20 11:17:16 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int	ft_lex_simple_quotes(const char *cmd_user, int *nb_chars_in_word)
{
	*nb_chars_in_word += 1;
	if (ft_strchr(cmd_user + *nb_chars_in_word, '\'') != NULL)
	{
		while (cmd_user[*nb_chars_in_word] != '\'')
		{
			if (cmd_user[*nb_chars_in_word] != '\\')
				*nb_chars_in_word += 1;
			else
				*nb_chars_in_word += 2;
		}
		*nb_chars_in_word += 1;
		return (1);
	}
	ft_dprintf(2, "Lexing error near '%c'\n", '\'');
	return (0);
}

int	ft_lex_double_quotes(const char *cmd_user, int *nb_chars_in_word)
{
	*nb_chars_in_word += 1;
	if (ft_strchr(cmd_user + *nb_chars_in_word, '"') != NULL)
	{
		while (cmd_user[*nb_chars_in_word] != '"')
		{
			if (cmd_user[*nb_chars_in_word] != '\\')
				*nb_chars_in_word += 1;
			else
				*nb_chars_in_word += 2;
		}
		*nb_chars_in_word += 1;
		return (1);
	}
	ft_dprintf(2, "Lexing error near '%c'\n", '"');
	return (0);
}
