/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:25:17 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/26 13:28:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				ft_find_char(char **str, int c)
{
	char *s;

	s = *str + 1;
	while (*s)
	{
		if (*s == '\\')
			s++;
		else if (*s == c)
		{
			*str = s;
			return (0);
		}
		s++;
	}
	*str = s;
	return (1);
}

int				ft_find_char_rc(char **str, int c)
{
	char *s;

	s = *str;
	while (*s)
	{
		if (*s == '\\')
			s++;
		else if (*s == c)
		{
			*str = s;
			return (0);
		}
		else if (*s == '"' || *s == '\'' || *s == '`')
			ft_find_char(&s, *s);
		if (*s)
			s++;
	}
	*str = s;
	return (1);
}

int				ft_check_p1(char **s, t_quotes *q)
{
	if (**s == '\\')
	{
		*s = *s + 1;
		return (0);
	}
	if (**s == '"')
	{
		if (ft_find_char(s, '"'))
			return (q->dquote = 1);
	}
	else if (**s == '\'')
	{
		if (ft_find_char(s, '\''))
			return (q->squote = 1);
	}
	else if (**s == '`')
	{
		if (ft_find_char(s, '`'))
			return (q->bquote = 1);
	}
	return (0);
}

int				ft_check_quotes(char *s, t_quotes *q)
{
	int		res;

	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\\' && ((*(s + 1) == 10 && *(s + 2) == 0) || *(s + 1) == 0))
			return ((q->escape = 1));
		if ((res = ft_check_p1(&s, q)))
			return (res);
		else if (*s == '(')
		{
			if (ft_find_char_rc(&s, ')'))
				return (q->parenthesis = 1);
		}
		else if (*s == '{')
		{
			if (ft_find_char_rc(&s, '}'))
				return (q->curly_bracket = 1);
		}
		if (*s)
			s++;
	}
	return (0);
}
