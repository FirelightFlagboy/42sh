/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:26 by anonymous          #+#    #+#             */
/*   Updated: 2018/03/02 21:13:07 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*dup_env_val(char *pt)
{
	size_t	sz;

	sz = 1;
	if (pt[sz] <= '9' && pt[sz] >= '1')
		return (NULL);
	while (((pt[sz] >= 'A' && pt[sz] <= 'Z') || pt[sz] == '_' ||
				(pt[sz] >= '1' && pt[sz] <= '9')))
		sz++;
	return (ft_strndup(pt, sz));
}

static int		quostatus_env(t_sh **sh, char **temp)
{
	char	*tmp;

	if (ft_strstr(*temp, "$?"))
	{
		tmp = ft_itoa((*sh)->ret);
		ft_str_replace(temp, "$?", tmp, 1);
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}

char			*quotes_env(char *temp, t_sh *sh)
{
	char	*pt;
	char	*env_val;
	char	*tmp;

	sh = gtsh(NULL);
	pt = temp;
	while (pt)
		if ((pt = ft_strchr(pt, '$')))
		{
			if (ft_isescaped(temp, pt - temp) && (++pt))
				continue;
			if (quostatus_env(&sh, &temp))
				continue ;
			if (!(tmp = dup_env_val(pt)))
				return (temp);
			if ((env_val = get_env_val(&sh, &(tmp[1]))))
			{
				ft_strnreplace(&temp, tmp, env_val, pt - temp);
				pt = temp;
			}
			else
				++pt;
			ft_strdel(&tmp);
		}
	return (temp);
}
