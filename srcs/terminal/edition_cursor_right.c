/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edition_cursor_right.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:38 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/11 10:13:05 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int			ft_checkcurrentline(t_sh **sh)
{
	int i;

	i = ft_currentline(sh);
	if (i == 0)
		i = 0;
	return (i);
}

static int			find_end(t_sh **sh, int i)
{
	if (i == 1)
	{
		if (ft_getpart(sh, NULL) + (*sh)->term->prompt_len
			< ft_linesize())
			tputs(tgoto(tgetstr("ch", NULL), 0,
			ft_getpart(sh, NULL) + (*sh)->term->prompt_len - 1), 0, ft_charput);
		else
			tputs(tgoto(tgetstr("ch", NULL), 0,
			(ft_getpart(sh, NULL) + (*sh)->term->prompt_len)
			% ft_linesize() - 1), 0, ft_charput);
		(*sh)->term->tc_in += 1;
	}
	else
	{
		if (ft_getpart(sh, NULL) <= ft_linesize())
			tputs(tgoto(tgetstr("ch", NULL), 0,
			ft_getpart(sh, NULL) - 1), 0, ft_charput);
		else
			tputs(tgoto(tgetstr("ch", NULL), 0,
			ft_getpart(sh, NULL) % ft_linesize() - 1), 0, ft_charput);
	}
	return (0);
}

static inline void	move_left_if(t_sh **sh)
{
	(*sh)->term->tc_in -= 1;
	tputs(tgetstr("up", NULL), 0, ft_charput);
	if (ft_isfirstline(sh))
		find_end(sh, 1);
	else
	{
		(*sh)->term->tc_in += 1;
		find_end(sh, 0);
	}
	(*sh)->term->tc_in -= 1;
}

void				move_left(t_sh **sh)
{
	if (!(*sh)->buff)
		return ;
	if ((*sh)->buff[(*sh)->term->tc_in - 1] == '\n')
	{
		return (move_left_if(sh));
	}
	if ((ft_isfirstline(sh) && ((*sh)->term->tc_in + (*sh)->term->
	prompt_len) % ft_linesize() == 0) || (!ft_isfirstline(sh) &&
	(ft_checkcurrentline(sh) % (ft_linesize() + 1) == 0)))
	{
		tputs(tgetstr("up", NULL), 0, ft_charput);
		tputs(tgoto(tgetstr("ch", NULL), 0, ft_linesize() - 1), 0, ft_charput);
	}
	else
		tputs(tgetstr("le", NULL), 0, ft_charput);
	(*sh)->term->tc_in -= 1;
	return ;
}

void				move_right(t_sh **sh, char *buff, int offset)
{
	if ((*sh)->buff[(*sh)->term->tc_in] == '\n' && offset == 1)
	{
		(*sh)->term->tc_in += 1;
		ft_put2str(tgetstr("do", NULL), tgoto(tgetstr("ch", NULL), 0, 0));
		return ;
	}
	if (offset == 0)
	{
		ft_put2str(tgetstr("im", NULL), buff);
		tputs(tgetstr("ei", NULL), 0, ft_charput);
		if ((ft_isfirstline(sh) && ((*sh)->term->tc_in + (*sh)->term->
		prompt_len) % ft_linesize() == 0) || (!ft_isfirstline(sh)
		&& (ft_checkcurrentline(sh) % ft_linesize() == 0)))
			ft_put2str(tgetstr("do", NULL), tgoto(tgetstr("ch", NULL), 0, 0));
		return ;
	}
	if ((ft_isfirstline(sh) && ((*sh)->term->tc_in + 1 + (*sh)->term->
	prompt_len) % ft_linesize() == 0) || (!ft_isfirstline(sh)
	&& ((ft_checkcurrentline(sh) + 1) % ft_linesize() == 0)))
		ft_put2str(tgetstr("do", NULL), tgoto(tgetstr("ch", NULL), 0, 0));
	else
		tputs(tgetstr("nd", NULL), 0, ft_charput);
	if (offset)
		(*sh)->term->tc_in += 1;
}
