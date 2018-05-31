/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:37:16 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/24 09:47:04 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_getenv(t_sh *sh, char *key)
{
	return (get_env_val(&sh, key));
}

char	*ft_get_val(t_sh *sh, char *key)
{
	t_locvar	*t;
	char		*s;

	if ((s = get_env_val(&sh, key)))
		return (s);
	if ((t = get_locvar_pos(sh, key)))
		return (t->val);
	return (NULL);
}
