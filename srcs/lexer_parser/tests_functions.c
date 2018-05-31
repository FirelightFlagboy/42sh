/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:48:58 by eduriez           #+#    #+#             */
/*   Updated: 2018/04/19 21:49:03 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int						ft_isspace_separator(const char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int						ft_is_start_op(const char c)
{
	if (c == ';' || c == '&' || c == '|' || c == '\n' || c == '<' || c == '>')
		return (1);
	return (0);
}

int						ft_is_ionumber(const char *str)
{
	if (ft_strlen(str) == 1 && ft_isdigit(str[0]))
		return (1);
	return (0);
}
