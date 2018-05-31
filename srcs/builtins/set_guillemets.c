/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_guillemets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 06:32:11 by ybensimo          #+#    #+#             */
/*   Updated: 2018/04/24 19:13:27 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	create_or_set(t_sh *sh, char *arg)
{
	t_locvar	*lo;

	lo = get_locvar_pos(sh, arg);
	if (!lo)
	{
		lo = new_locvar(sh, arg, NULL);
		lo->isguillemet = 0;
		lo->isexport = 0;
	}
}

void	set_valeur(t_sh *sh, char *arg)
{
	char		*var;
	char		*val;
	char		*s;
	t_locvar	*lo;

	s = ft_strchr(arg, '=');
	var = arg;
	val = s + 1;
	*s = 0;
	lo = get_locvar_pos(sh, var);
	if (lo)
	{
		free(lo->val);
		lo->val = ft_strdup(val);
	}
	else
	{
		lo = new_locvar(sh, var, val);
		lo->isexport = 0;
	}
	lo->isguillemet = 0;
}

void	set_guillemets(t_sh *sh, char *arg)
{
	char		*var;
	char		*val;
	char		*s;
	t_locvar	*lo;

	s = ft_strchr(arg, '=');
	var = arg;
	*s = 0;
	ft_asprintf(&val, "\"%s\"", s + 1);
	lo = get_locvar_pos(sh, var);
	if (lo)
	{
		free(lo->val);
		lo->val = ft_strdup(val);
	}
	else
	{
		lo = new_locvar(sh, var, val);
		lo->isexport = 0;
	}
	lo->isguillemet = 1;
	free(val);
}
