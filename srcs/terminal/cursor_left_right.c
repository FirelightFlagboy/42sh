/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_left_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:19 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/11 09:34:35 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				move_cursor_sides(t_sh **sh, unsigned int key)
{
	int		i;

	if (!(*sh)->buff)
		return ;
	if ((key == BTN_LEFT || key == BTN_HOME) && (*sh)->term->tc_in > 0)
	{
		i = (key == BTN_LEFT ? 1 : ((*sh)->term->tc_in));
		while ((i-- != 0))
			move_left(sh);
	}
	else if ((key == BTN_RIGHT || key == BTN_END) &&
		(*sh)->term->tc_in < (*sh)->term->tc_len)
	{
		i = (key == BTN_RIGHT ? 1 : (*sh)->term->tc_len -
			(*sh)->term->tc_in);
		while ((i-- > 0))
			move_right(sh, NULL, 1);
	}
}

static inline void	move_cursor_alt_else(t_sh **s)
{
	while ((*s)->buff[(*s)->term->tc_in]
	&& ft_isspace((*s)->buff[(*s)->term->tc_in]))
		move_right(s, NULL, 1);
	while ((*s)->buff[(*s)->term->tc_in]
	&& !((ft_isspace((*s)->buff[(*s)->term->tc_in])
	|| (*s)->term->tc_in >= (*s)->term->tc_len)))
		move_right(s, NULL, 1);
	while ((*s)->buff[(*s)->term->tc_in]
	&& ((ft_isspace((*s)->buff[(*s)->term->tc_in])
	|| (*s)->term->tc_in >= (*s)->term->tc_len - 1)))
		move_right(s, NULL, 1);
}

void				move_cursor_alt(t_sh **s, unsigned int key)
{
	if (((*s)->term->tc_in <= 0 && key == BTN_ALEFT)
	|| ((*s)->term->tc_in > (*s)->term->tc_len && key == BTN_ARIGHT)
	|| (*s)->buff == NULL)
		return ;
	if (key == BTN_ALEFT)
	{
		if ((*s)->term->tc_in > 0
		&& ft_isspace((*s)->buff[(*s)->term->tc_in - 1]))
			move_left(s);
		while ((*s)->term->tc_in > 0
		&& ft_isspace((*s)->buff[(*s)->term->tc_in]))
			move_left(s);
		while ((*s)->term->tc_in > 0
		&& !ft_isspace((*s)->buff[(*s)->term->tc_in - 1]))
			move_left(s);
	}
	else
	{
		move_cursor_alt_else(s);
	}
}
