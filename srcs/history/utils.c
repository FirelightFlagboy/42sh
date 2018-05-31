/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:34 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 14:16:58 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** print history
*/

int				print_history(t_sh **sh)
{
	t_h_lst		*l;
	int			i;
	int			d;

	l = (*sh)->history->list;
	i = 0;
	while (l->next)
	{
		l = l->next;
		i++;
	}
	d = 1;
	while (i /= 10)
		d++;
	while (l)
	{
		ft_printf("%-*d%s\n", d + 1, l->index, l->cmd);
		l = l->prev;
	}
	return (0);
}

/*
** get specific elem from history
*/

t_h_lst			*hist_at_index(t_sh **sh, int index)
{
	t_h_lst *l;

	l = (*sh)->history->list;
	while (l && l->index != index)
		l = l->next;
	return (l);
}

/*
** Create new element history
*/

static t_h_lst	*hist_new_node(char *cmd)
{
	t_h_lst	*l;

	if (!cmd)
		return (NULL);
	if (!(l = (t_h_lst *)ft_memalloc(sizeof(t_h_lst))))
		return (NULL);
	l->cmd = ft_strdup(cmd);
	l->next = NULL;
	return (l);
}

void			hist_add_from_str(char *str)
{
	t_sh	*sh;
	t_h_lst	*new;

	if (str == NULL)
		return ;
	sh = gtsh(0);
	if (sh->history->list && ft_strcmp(str, sh->history->list->cmd) == 0)
		return ;
	if (!(new = hist_new_node(str)))
		return ;
	new->next = sh->history->list;
	if (sh->history->list)
		sh->history->list->prev = new;
	sh->history->list = new;
	new->index = sh->history->size;
	sh->history->size++;
}

/*
** Add new element to history from sh buffer
*/

void			hist_add(t_sh **sh)
{
	t_h_lst	*new;

	if ((*sh)->history->list &&
		ft_strcmp((*sh)->buff, (*sh)->history->list->cmd) == 0)
		return ;
	if (!(new = hist_new_node((*sh)->buff)))
		return ;
	new->next = (*sh)->history->list;
	if ((*sh)->history->list)
		(*sh)->history->list->prev = new;
	(*sh)->history->list = new;
	new->index = (*sh)->history->size;
	(*sh)->history->size++;
}
