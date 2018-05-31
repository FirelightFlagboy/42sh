/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:29:50 by ybensimo          #+#    #+#             */
/*   Updated: 2018/04/25 10:08:34 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		remove_locvar(t_sh *sh, t_locvar *cur)
{
	t_locvar	*next;
	t_locvar	*prev;

	if (cur->var)
		free(cur->var);
	if (cur->val)
		free(cur->val);
	if (!cur->prev)
	{
		if (cur->next)
			cur->next->prev = NULL;
		sh->locvar = cur->next;
		free(cur);
		return ;
	}
	next = cur->next;
	prev = cur->prev;
	free(cur);
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
}

static void	unset_env(t_sh *sh, char const *cmd)
{
	t_envl		*nv;
	t_envl		*prev;

	prev = NULL;
	nv = sh->env_list;
	while (nv && ft_strcmp(nv->name, cmd))
	{
		prev = nv;
		nv = nv->next;
	}
	if (nv)
	{
		if (nv->value)
			free(nv->value);
		free(nv->name);
		if (prev)
			prev->next = nv->next;
		else
			sh->env_list = nv->next;
		free(nv);
		rebuild_str2env(&sh);
	}
}

int			ft_unset(t_sh **sh)
{
	int			i;
	t_locvar	*cur;

	if ((*sh)->cmd[1])
	{
		i = 1;
		while ((*sh)->cmd[i])
		{
			cur = (*sh)->locvar;
			while (cur && ft_strcmp((*sh)->cmd[i], cur->var))
				cur = cur->next;
			if (cur)
				remove_locvar(*sh, cur);
			unset_env(*sh, (*sh)->cmd[i]);
			i++;
		}
	}
	return (0);
}
