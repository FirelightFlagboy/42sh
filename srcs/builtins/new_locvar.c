/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_locvar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:36:19 by ybensimo          #+#    #+#             */
/*   Updated: 2018/05/02 15:45:55 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	type_of_initial_export(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (2);
		i++;
	}
	return (0);
}

void		initial_export(t_sh *sh, char *var, char *val)
{
	int			eq;
	t_locvar	*lo;

	eq = type_of_initial_export(val);
	if (eq > 1)
	{
		lo = new_locvar(sh, var, val);
		lo->isguillemet = 1;
	}
	else
	{
		lo = new_locvar(sh, var, val);
		lo->isguillemet = 0;
	}
	lo->isexport = 1;
}

t_locvar	*new_locvar(t_sh *sh, char *var, char *val)
{
	t_locvar	*new;
	t_locvar	*cur;

	if ((new = (t_locvar *)malloc(sizeof(t_locvar))) == NULL)
		malloc_error();
	new->var = ft_strdup(var);
	if (val)
		new->val = ft_strdup(val);
	else
		new->val = NULL;
	new->next = NULL;
	new->prev = NULL;
	if (!sh->locvar)
		sh->locvar = new;
	else
	{
		cur = sh->locvar;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
	}
	return (new);
}
