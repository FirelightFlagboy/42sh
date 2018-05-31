/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_guillemets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 06:32:11 by ybensimo          #+#    #+#             */
/*   Updated: 2018/04/24 12:52:58 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	create_or_export(t_sh *sh, char *arg)
{
	t_locvar	*lo;

	lo = get_locvar_pos(sh, arg);
	if (!lo)
	{
		lo = new_locvar(sh, arg, NULL);
		lo->isguillemet = 0;
	}
	lo->isexport = 1;
	if (lo->val)
		change_env_export(sh, lo->var, lo->val);
}

void	export_valeur(t_sh *sh, char *arg)
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
	}
	lo->isexport = 1;
	lo->isguillemet = 0;
	change_env_export(sh, var, val);
}

void	export_guillemets(t_sh *sh, char *arg)
{
	char		*var;
	char		*val;
	char		*s;
	t_locvar	*lo;

	s = ft_strchr(arg, '=');
	var = arg;
	ft_asprintf(&val, "\"%s\"", s + 1);
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
	}
	lo->isexport = 1;
	lo->isguillemet = 1;
	change_env_export(sh, var, val);
	free(val);
}
