/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:24 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 16:13:50 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		clean_history(t_h_lst **lst)
{
	t_h_lst	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_strdel(&tmp->cmd);
		free(tmp);
	}
}

void		closesh(t_sh **sh)
{
	save_history_file(*sh);
	ft_str2del(&(*sh)->env);
	ft_strdel(&(*sh)->hist_dir);
	clean_env_list(&(*sh)->env_list);
	clean_history(&(*sh)->history->list);
	ft_memdel((void **)(&(*sh)->history));
	ft_memdel((void **)&(*sh)->term);
	free((*sh)->q);
}
