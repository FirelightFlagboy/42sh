/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 04:43:06 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 16:39:30 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Create and return the shell,
** pass the environment
*/

void		init_locvar(t_sh *sh)
{
	t_envl	*cur;

	cur = sh->env_list;
	while (cur)
	{
		if (cur->name)
			initial_export(sh, cur->name, cur->value);
		cur = cur->next;
	}
}

t_sh		*gtsh(char **env)
{
	static t_sh	sh;
	int			i;

	if (sh.term == NULL)
	{
		sh.exit = 0;
		g_exit = 0;
		sh.hash_pwd = NULL;
		if (!(sh.term = ft_memalloc(sizeof(t_term)))\
		|| !(sh.history = ft_memalloc(sizeof(t_hist))))
			malloc_error();
		sh.history->list = NULL;
		sh.clipboard = NULL;
		sh.ret = 0;
		sh.locvar = NULL;
	}
	if (env)
	{
		i = 0;
		initenv(&sh, env);
		init_locvar(&sh);
	}
	return (&sh);
}
