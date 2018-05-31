/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_end_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:28:11 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/11 08:35:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*read_join_tab(char **t)
{
	char	*r;
	char	*tmp;

	if (*t == NULL)
		return (NULL);
	r = 0;
	while (*t)
	{
		if (r)
		{
			tmp = r;
			ft_asprintf(&r, "%s %s", r, *t);
			free(tmp);
		}
		else
			r = ft_strdup(*t);
		t++;
	}
	return (r);
}

void	read_set_assign(t_sh *sh, char *key, char *value)
{
	t_locvar	*lo;
	char		*s;

	s = key;
	while (*s)
		if (ft_isalnum(*s++) == 0)
			ft_eprintf("read : %s : not a valid identifier\n", key);
	lo = get_locvar_pos(sh, key);
	s = 0;
	if (lo)
	{
		free(lo->val);
		lo->val = ft_strdup(value);
	}
	else
	{
		s = ft_strdup(key);
		new_locvar(sh, s, value);
		ft_strdel(&s);
	}
}

void	read_do_assign(t_sh *sh, char **t, char **var)
{
	int		i;
	char	*s;

	i = 0;
	(void)sh;
	while (var && var[i])
	{
		if (!var[i + 1])
		{
			read_set_assign(sh, var[i], (s = read_join_tab(t)));
			ft_strdel(&s);
			break ;
		}
		else
		{
			read_set_assign(sh, var[i], *t);
			if (*t)
				t++;
		}
		i++;
	}
}
