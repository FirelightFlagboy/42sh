/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:39:51 by ybensimo          #+#    #+#             */
/*   Updated: 2018/04/26 16:49:56 by ybensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	display_set(t_sh *sh)
{
	t_locvar	*cur;

	cur = sh->locvar;
	while (cur)
	{
		if (cur->val)
			ft_printf("set %s=%s\n", cur->var, cur->val);
		else
			ft_printf("set %s\n", cur->var);
		cur = cur->next;
	}
}

int			ft_set(t_sh **sh)
{
	int			i;
	int			eq;

	if (!(*sh)->cmd[1])
		display_set(*sh);
	else
	{
		i = 1;
		while ((*sh)->cmd[i])
		{
			eq = type_of_export((*sh)->cmd[i]);
			if (eq > 1)
				set_guillemets(*sh, (*sh)->cmd[i]);
			else if (eq == 1)
				set_valeur(*sh, (*sh)->cmd[i]);
			else if (eq == 0)
				create_or_set(*sh, (*sh)->cmd[i]);
			i++;
		}
	}
	return (0);
}
