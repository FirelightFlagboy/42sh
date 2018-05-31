/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:52 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/24 16:16:18 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** create new env element with name and value
*/

t_envl		*envlnew(char *name, char *value)
{
	t_envl *envlist;
	size_t n;

	envlist = (t_envl *)ft_memalloc(sizeof(*envlist));
	if (!envlist)
		return (NULL);
	if (name)
	{
		n = ft_strlen(name);
		if ((envlist->name = ft_strnew(n + 1)))
			ft_strcpy(envlist->name, name);
		else
			return (NULL);
	}
	if (value)
	{
		n = ft_strlen(value);
		if ((envlist->value = ft_strnew(n + 1)))
			ft_strcpy(envlist->value, value);
		else
			return (NULL);
	}
	envlist->next = NULL;
	return (envlist);
}

void		rebuild_str2env(t_sh **sh)
{
	t_envl	*tmp;
	char	**new;
	int		i;

	i = 0;
	tmp = (*sh)->env_list;
	new = ft_str2new(env_lst_size(tmp));
	while (tmp)
	{
		new[i] = ft_str3join(tmp->name, "=", tmp->value);
		tmp = tmp->next;
		i++;
	}
	ft_str2del(&(*sh)->env);
	(*sh)->env = new;
}

void		clean_env_list(t_envl **begin_list)
{
	t_envl *tmp;

	while (*begin_list)
	{
		tmp = *begin_list;
		ft_strdel(&((*begin_list)->name));
		ft_strdel(&((*begin_list)->value));
		*begin_list = tmp->next;
		free(tmp);
	}
}
