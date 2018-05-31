/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 09:59:47 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/30 11:35:22 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		move_page_up(t_sh *sh)
{
	t_term	*term;
	int		move;

	term = sh->term;
	if (term->tc_in > term->ws_col)
		move = ((term->tc_in + term->prompt_len) % term->ws_col - 1) + 1;
	else
		move = ((term->tc_in) % term->ws_col - 1);
	if (term->tc_len <= 0)
		return ;
	while (move >= 0)
	{
		move_left(&sh);
		move--;
	}
}

void		move_page_down(t_sh *sh)
{
	t_term	*term;
	int		move;

	term = sh->term;
	if (!term->tc_len)
		return ;
	move = ((term->tc_in + term->prompt_len) % term->ws_col - 1) + 1;
	move = term->ws_col - move;
	if (move > term->tc_len - term->tc_in)
		move = term->tc_len - term->tc_in;
	while (move > 0)
	{
		move_right(&sh, NULL, 1);
		move--;
	}
}

void		move_page(t_sh **sh, uint key)
{
	(void)sh;
	if (key == BTN_PAGE_UP)
	{
		ft_dprintf(9, "page up:\n");
		move_page_up(*sh);
	}
	else if (key == BTN_PAGE_DOWN)
	{
		ft_dprintf(9, "page down:\n");
		move_page_down(*sh);
	}
}
