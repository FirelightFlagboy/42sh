/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:04:18 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/24 16:01:19 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		get_dir(t_sh **sh)
{
	char *tmp;

	tmp = search_cmd(*sh);
	if (check_dir(tmp))
	{
		if (tmp[ft_strlen(tmp) - 1] != '/')
		{
			ft_strdel(&tmp);
			ft_putstr(tgoto(tgetstr("UP", NULL), 0, 2));
			ft_putstr(tgoto(tgetstr("ch", NULL), 0, (*sh)->term->prompt_len
						+ (*sh)->term->tc_in));
			work_buffer(sh, "/");
			return (1);
		}
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (0);
}
