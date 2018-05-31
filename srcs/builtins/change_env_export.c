/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:06:38 by ybensimo          #+#    #+#             */
/*   Updated: 2018/04/24 18:17:56 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	add_env_export(t_sh *sh, char *var, char *val, t_envl *prev)
{
	t_envl	*new;

	if (!(new = (t_envl *)malloc(sizeof(t_envl))))
		exit(0);
	new->name = ft_strdup(var);
	new->value = ft_strdup(val);
	new->next = NULL;
	if (prev)
		prev->next = new;
	else
		sh->env_list = new;
}

void	change_env_export(t_sh *sh, char *var, char *val)
{
	t_envl	*cur;
	t_envl	*prev;

	if (!(cur = sh->env_list))
		return ;
	while (cur && ft_strcmp(cur->name, var))
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur)
	{
		if (cur->value)
			free(cur->value);
		cur->value = ft_strdup(val);
	}
	else
	{
		add_env_export(sh, var, val, prev);
	}
	rebuild_str2env(&sh);
}
