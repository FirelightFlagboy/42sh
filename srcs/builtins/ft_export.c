/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:39:51 by ybensimo          #+#    #+#             */
/*   Updated: 2018/04/27 14:00:44 by ybensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			type_of_export(char *str)
{
	int		i;
	int		eq;

	i = 0;
	eq = 0;
	if (!str || str[0] == '=')
		return (-1);
	while (str[i])
	{
		if (str[i] == '=')
			eq++;
		if (eq > 1)
			return (eq);
		i++;
	}
	return (eq);
}

t_locvar	*get_locvar_pos(t_sh *sh, char *var)
{
	t_locvar	*cur;

	cur = sh->locvar;
	while (cur && cur->var && ft_strcmp(cur->var, var))
		cur = cur->next;
	return (cur);
}

static void	display_export(t_sh *sh)
{
	t_locvar	*cur;

	cur = sh->locvar;
	while (cur)
	{
		if (cur->isexport == 1)
		{
			if (cur->val)
				ft_printf("export %s=%s\n", cur->var, cur->val);
			else
				ft_printf("export %s\n", cur->var);
		}
		cur = cur->next;
	}
}

int			ft_export(t_sh **sh)
{
	int			i;
	int			eq;

	if (!(*sh)->cmd[1])
		display_export(*sh);
	else
	{
		i = 1;
		while ((*sh)->cmd[i])
		{
			eq = type_of_export((*sh)->cmd[i]);
			if (eq > 1)
				export_guillemets(*sh, (*sh)->cmd[i]);
			else if (eq == 1)
				export_valeur(*sh, (*sh)->cmd[i]);
			else if (eq == 0)
				create_or_export(*sh, (*sh)->cmd[i]);
			i++;
		}
	}
	return (0);
}
