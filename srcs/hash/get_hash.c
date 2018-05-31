/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:32:18 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/08 09:11:28 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_hash	**get_hash(void)
{
	static t_hash *hash[HASH_SIZE + 1];

	return (hash);
}

int		no_need_to_refresh(t_sh *sh)
{
	t_locvar	*t;
	char		*s;

	if (sh->hash_pwd == NULL)
	{
		return (0);
	}
	s = get_env_val(&sh, "PATH");
	t = get_locvar_pos(sh, "PATH");
	if ((s && !ft_strcmp(s, sh->hash_pwd))\
	|| (t && !ft_strcmp(t->val, sh->hash_pwd)))
		return (1);
	return (0);
}
