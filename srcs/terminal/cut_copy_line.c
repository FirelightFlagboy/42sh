/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_copy_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:26 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/25 09:46:36 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		cut_to_buff(t_sh **sh, int from, int size, char **tmp)
{
	if (!(*sh)->buff || (*sh)->buff[0] == '\0')
		return ;
	*tmp = ft_strndelat((*sh)->buff, from, size);
	(*sh)->clipboard = ft_strndup(&(*sh)->buff[from], size);
}

void		cut_line(t_sh **sh, unsigned int key)
{
	char	*tmp;
	char	*tmp1;

	if (!(*sh)->buff || (*sh)->buff[0] == '\0')
		return ;
	tmp = (*sh)->buff;
	tmp1 = (*sh)->clipboard;
	if (key == BTN_CTRL_K)
		cut_to_buff(sh, 0, (*sh)->term->tc_in, &tmp);
	else
		cut_to_buff(sh, (*sh)->term->tc_in,\
					(*sh)->term->tc_len - (*sh)->term->tc_in, &tmp);
	while ((*sh)->term->tc_in)
		move_left(sh);
	ft_strdel(&(*sh)->buff);
	reset_line(sh);
	work_buffer(sh, tmp);
	move_cursor_sides(sh, (key == BTN_CTRL_K) ? BTN_HOME : BTN_END);
	ft_strdel(&tmp);
	ft_strdel(&tmp1);
}

void		copy(t_sh **sh)
{
	char	*tmp;

	if (!(*sh)->buff || (*sh)->buff[0] == '\0')
		return ;
	tmp = (*sh)->clipboard;
	(*sh)->clipboard = ft_strdup((*sh)->buff);
	ft_strdel(&tmp);
}
