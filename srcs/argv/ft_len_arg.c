/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:47:15 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/11 09:52:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_len_nb_argv(int nb)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int	ft_len_env(char **ps)
{
	char	*s;
	int		i;
	char	env[2048];

	s = *ps;
	i = 1;
	if (*s == '~')
		ft_strcpy(env, "HOME");
	else
	{
		i = ft_get_env_name(env, s);
		env[i - 1] = 0;
	}
	*ps = s + i;
	if (ft_env_is_special_case(env))
		return (ft_len_nb_argv(ft_get_env_special_case(env)));
	else if (!(s = ft_get_val(gtsh(NULL), env)))
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void		ft_len_arg_loop(char *t, char **a, int *res, char *g)
{
	if (*t != '\'' && **a == '\\')
	{
		*res = *res + 1;
		*a = *a + 1;
	}
	else if (**a != *t)
		*res = *res + 1;
	else if (g != *a)
		*t = 0;
}

int			ft_len_arg(char *a)
{
	int		res;
	char	prev;
	char	t;
	char	*g;

	res = 0;
	prev = 0;
	t = 0;
	g = 0;
	while (*a)
	{
		if (!t && (*a == '\'' || *a == '"') && (g = a))
			t = *a;
		if (t != '\'' && (*a == '$'\
		|| (*a == '~' && (a[1] == '/' || !a[1]) && ft_isspace(prev))))
		{
			res += ft_len_env(&a);
			continue;
		}
		ft_len_arg_loop(&t, &a, &res, g);
		prev = *a;
		if (*a)
			a++;
	}
	return (res);
}
