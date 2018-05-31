/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:20:32 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/08 09:12:54 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Start loop
** print prompt
** handle quotes
** handle hist expansions
** add to history
*/

#include "sh.h"

static inline void	start_init(t_sh *sh)
{
	int		disp;

	disp = 0;
	if (sh->debug & 0b100 && !no_need_to_refresh(sh))
		disp = 1;
	ft_refresh_hash();
	if (disp)
		ft_print_hash();
	sh->history->at_index = -1;
	print_prompt(&sh, NULL);
	interceptsig();
	sh->inhere = 0;
	sh->sig = fctsig;
}

int					start(t_sh *sh)
{
	while (sh->exit != 1)
	{
		start_init(sh);
		if (sh->term->tc_ok)
			read_input(&sh, NULL);
		else
		{
			if (get_next_line(0, &sh->buff) == 0)
				return (0);
		}
		do_quotes(&sh);
		if (validate_and_prep_cmd(&sh) == -1)
		{
			ft_strdel(&(sh->buff));
			continue ;
		}
		hist_add(&sh);
		sh->ast = ft_get_ast(sh->buff);
		if (sh->ast != NULL)
			evalcmd(sh);
		ft_strdel(&(sh->buff));
	}
	return (sh->ret);
}
