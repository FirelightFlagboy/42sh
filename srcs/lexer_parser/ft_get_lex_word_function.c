/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lex_word_function.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:47:37 by eduriez           #+#    #+#             */
/*   Updated: 2018/04/19 21:47:42 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

t_lex_word_func	ft_get_lex_word_function(const char start_op)
{
	const char				start_operators[] = "<>\n|&;";
	const t_lex_word_func	functions_operators[] = {&ft_manage_less_operators,
	&ft_manage_great_operators, &ft_manage_newline_operator,
	&ft_manage_or_operators, &ft_manage_and_operators,
	&ft_manage_semicolon_operators};
	int						index_func;

	index_func = ft_strchr_index(start_operators, start_op);
	if (index_func == -1)
		return (&ft_process_word);
	return (functions_operators[index_func]);
}
