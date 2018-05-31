/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:57:55 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/11 09:55:54 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	ft_process_escapes(char c, char type)
{
	if (type == '\'')
		return (c);
	if (c == 't')
		return ('\t');
	else if (c == 'v')
		return ('\v');
	else if (c == 'n')
		return ('\n');
	else if (c == 'r')
		return ('\r');
	else if (c == 'e')
		return ('\e');
	else if (c == 'a')
		return ('\a');
	else if (c == 'f')
		return ('\f');
	else if (c == 'b')
		return ('\b');
	return (c);
}

static void	ft_fill_env(char *d, char **s, int *i)
{
	char	*e;
	char	env[2048];
	int		p;

	e = *s;
	p = 1;
	if (*e == '~')
		ft_strcpy(env, "HOME");
	else
	{
		p = ft_get_env_name(env, e);
		env[p - 1] = 0;
	}
	*s = e + p;
	if (ft_env_is_special_case(env))
		e = ft_itoa_cte(ft_get_env_special_case(env));
	else if (!(e = ft_get_val(gtsh(NULL), env)))
		return ;
	p = -1;
	while (e[++p])
		d[*i + p] = e[p];
	d[*i + p] = 0;
	*i = *i + p;
}

static void	ft_loop(char *d, char **str[2], char *type, int *ia)
{
	char	*s;
	char	*t;
	int		i;

	s = str[0][0];
	t = str[1][0];
	i = *ia;
	if (*type != '\'' && *s == '\\')
	{
		if (*(s + 1) != '\n')
			d[i++] = ft_process_escapes(*(s + 1), *type);
		if (*s)
			s++;
	}
	else if (*s != *type)
		d[i++] = *s;
	else if (t != s)
		*type = 0;
	*ia = i;
	str[0][0] = s;
}

void		ft_fill_arg(char *d, char *s)
{
	char	type;
	int		i;
	char	prev;
	char	*t;

	type = 0;
	prev = 0;
	i = 0;
	t = 0;
	while (*s)
	{
		if (type == 0 && (*s == '\'' || *s == '"') && (t = s))
			type = *s;
		if (type != '\'' &&\
		(*s == '$'\
		|| (*s == '~' && (s[1] == '/' || s[1] == 0) && ft_isspace(prev))))
		{
			ft_fill_env(d, &s, &i);
			continue;
		}
		ft_loop(d, (char **[2]){&s, &t}, &type, &i);
		prev = *s;
		s += (*s) ? 1 : 0;
	}
	d[i] = 0;
}
