/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edition.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:33 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 14:24:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	put_space(t_sh **sh)
{
	if (ft_isfirstline(sh) &&
			((ft_currentline(sh) + (*sh)->term->prompt_len)
			% (ft_linesize()) == 0))
	{
		ft_putchar(' ');
		ft_putstr(tgetstr("le", NULL));
	}
	else if (!ft_isfirstline(sh) &&
			(ft_currentline(sh) % (ft_linesize()) == 0))
	{
		ft_putchar(' ');
		ft_putstr(tgetstr("le", NULL));
	}
	else if (!ft_isfirstline(sh) && ft_currentline(sh) > ft_linesize() &&
			((ft_currentline(sh) + 1) % (ft_linesize()) == 0))
	{
		ft_putchar(' ');
		ft_putchar(' ');
	}
}

void	clear_cmdline(t_sh **sh)
{
	int i;

	i = 0;
	back_to_prompt(sh, 1);
	ft_putstr(tgoto(tgetstr("ch", NULL), 0,
				(*sh)->term->prompt_len));
	ft_putstr(tgetstr("cd", NULL));
}

void	goto_endcmdline(t_sh **sh)
{
	while ((*sh)->term->tc_in < (*sh)->term->tc_len)
		move_right(sh, NULL, 1);
}

void	back_to_prompt(t_sh **sh, int keep)
{
	int line;

	line = (*sh)->term->tc_in;
	if ((*sh)->term->tc_len == 0)
	{
		(*sh)->term->tc_in = 0;
		return ;
	}
	while ((*sh)->term->tc_in != 0)
		move_left(sh);
	if (keep == 1)
		(*sh)->term->tc_in = line;
}

void	ft_printbuffer(t_sh **sh)
{
	int i;

	i = (*sh)->term->tc_in;
	tputs(tgetstr("vi", NULL), 0, ft_charput);
	tputs(tgetstr("cd", NULL), 0, ft_charput);
	if ((*sh)->buff)
	{
		ft_putstr((*sh)->buff + (*sh)->term->tc_in);
		(*sh)->term->tc_in = (*sh)->term->tc_len;
		put_space(sh);
	}
	while ((*sh)->term->tc_in != i)
		move_left(sh);
	tputs(tgetstr("ve", NULL), 0, ft_charput);
}
