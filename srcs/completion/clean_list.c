/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:44:18 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 10:30:38 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	clean_list(t_c_tab *list)
{
	t_c_tab *tmp;

	while (list)
	{
		ft_strdel(&list->content);
		ft_strdel(&list->name);
		ft_strdel(&list->perm);
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
