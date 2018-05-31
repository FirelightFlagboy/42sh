/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:26 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 16:42:26 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			set_hist_of_index(t_sh **sh, int index)
{
	t_h_lst	*lst;

	ft_strdel(&(*sh)->buff);
	if (index == -1)
		return ;
	lst = hist_at_index(sh, index);
	work_buffer(sh, lst->cmd);
}

static void		find_next_hist(t_sh **sh)
{
	if ((*sh)->history->at_index == -1)
		(*sh)->history->at_index = (*sh)->history->size - 1;
	else
		(*sh)->history->at_index--;
}

static void		find_prev_hist(t_sh **sh)
{
	if ((*sh)->history->at_index == (*sh)->history->size - 1)
		(*sh)->history->at_index = -1;
	else
		(*sh)->history->at_index++;
}

void			history(t_sh **sh, unsigned int key)
{
	t_hist	*h;

	h = (*sh)->history;
	if (!h->list ||
	(key == BTN_UP && h->at_index == 0) ||
	(key == BTN_DOWN && (h->at_index == -1)))
		return ;
	clear_cmdline(sh);
	reset_line(sh);
	(key == BTN_UP) ? find_next_hist(sh) : find_prev_hist(sh);
	set_hist_of_index(sh, (*sh)->history->at_index);
}
