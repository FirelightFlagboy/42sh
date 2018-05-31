/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:43 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/28 15:18:44 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		clean_buffer(t_sh **tsh)
{
	t_sh	*sh;

	sh = *tsh;
	ft_strdel(&sh->tmp_buff);
	ft_strdel(&sh->buff);
	sh->buff = ft_strdup("\0");
	ft_putchar('\n');
	reset_line(tsh);
	print_prompt(tsh, NULL);
}

static int	buffer_bol(t_sh **sh)
{
	ft_putstr(tgetstr("le", NULL));
	((*sh)->term->tc_in -= 1);
	return (1);
}

static void	delete_secondline(t_sh **sh)
{
	(*sh)->term->tc_in += 1;
	ft_putstr(tgoto(tgetstr("ch", NULL), 0, ft_getpart(sh, NULL) - 1));
	(*sh)->term->tc_in -= 1;
}

void		modify_buffer(t_sh **sh, unsigned int key)
{
	char	*tmp;

	if ((key == BTN_DEL && (*sh)->term->tc_in == (*sh)->term->tc_len) ||
		(key == BTN_BACK && (*sh)->term->tc_in == 0))
		return ;
	key == BTN_BACK ? buffer_bol(sh) : 0;
	(*sh)->term->tc_len -= 1;
	tmp = (*sh)->buff;
	if ((*sh)->buff[(*sh)->term->tc_in] == '\n')
	{
		if (ft_isfirstline(sh))
			ft_putstr(tgoto(tgetstr("ch", NULL), 0,
			ft_getpart(sh, NULL) + (*sh)->term->prompt_len - 1));
		else
			delete_secondline(sh);
		(key == BTN_BACK) ? ft_putstr(tgetstr("up", NULL)) : (void)0;
	}
	(*sh)->buff = ft_strndelat((*sh)->buff,
			(*sh)->term->tc_in, (size_t)1);
	ft_printbuffer(sh);
	ft_strdel(&tmp);
}

void		cmd_rewrite(t_sh **sh)
{
	clear_cmdline(sh);
	ft_putstr((*sh)->buff);
	(*sh)->term->tc_in = (*sh)->term->tc_len;
}
