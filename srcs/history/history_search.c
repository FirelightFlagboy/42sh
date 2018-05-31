/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:28 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/25 16:15:11 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** find in history list the first command that match s
*/

char	*history_search_first_match(t_sh **sh, char *s)
{
	t_h_lst	*h_lst;

	h_lst = (*sh)->history->list;
	while (h_lst)
	{
		if (h_lst->cmd && ft_strncmp(h_lst->cmd, s, ft_strlen(s)) == 0)
			return (h_lst->cmd);
		h_lst = h_lst->next;
	}
	return (NULL);
}

/*
** find in history list the first command that match argument s
*/

char	*history_search_first_arg_match(t_sh **sh, char *s)
{
	t_h_lst	*h_lst;
	char	*cmpr;
	int		i;

	h_lst = (*sh)->history->list;
	while (h_lst)
	{
		i = 0;
		while (!(h_lst->cmd[i] == ' ' || h_lst->cmd[i] == '\0'))
			i++;
		if (h_lst->cmd[i] == '\0')
		{
			h_lst = h_lst->next;
			continue ;
		}
		while (h_lst->cmd[i] == ' ')
			i++;
		cmpr = &h_lst->cmd[i];
		if (ft_strncmp(cmpr, s, ft_strlen(s)) == 0)
			return (h_lst->cmd);
		h_lst = h_lst->next;
	}
	return (NULL);
}
