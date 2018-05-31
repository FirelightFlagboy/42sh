/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_lst_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:32:49 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 16:38:49 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		swap_nodes(char **one, char **two)
{
	char *tmp;

	tmp = *two;
	*two = *one;
	*one = tmp;
}

void			tab_lst_sort(t_c_tab **begin_list)
{
	t_c_tab		*tmp;
	int			sorted;

	if (!(*begin_list))
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		tmp = *begin_list;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->content, tmp->next->content) > 0)
			{
				sorted = 0;
				swap_nodes(&tmp->content, &tmp->next->content);
			}
			tmp = tmp->next;
		}
	}
}
