/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:43 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/07 15:57:47 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		clear_prompt(t_sh **sh)
{
	tputs(tgetstr("vi", 0), 0, ft_charput);
	tputs(tgetstr("cl", 0), 0, ft_charput);
	print_prompt(sh, (*sh)->prompt);
	if ((*sh)->buff)
	{
		(*sh)->term->tc_in = (*sh)->term->tc_len;
		ft_putstr((*sh)->buff);
	}
	tputs(tgetstr("ve", 0), 0, ft_charput);
}

void		check_if_good_place(void)
{
	char	s[50 + 1];
	char	*t;
	size_t	rt;

	ft_putstr("\e[6n");
	if ((rt = read(STDIN_FILENO, s, 50)) > 0)
	{
		s[rt] = 0;
		t = ft_strchr(s, ';');
		if (ft_strcmp(t, ";1R"))
			ft_putstr("\e[0m\e[7;1m%\e[0m\n");
		rt = 0;
		if (ft_strchr(s, 'R') == NULL)
			while (read(STDIN_FILENO, &rt, sizeof(size_t)) > 0)
			{
				if (ft_strchr((char*)&rt, 'R'))
					return ;
				rt = 0;
			}
	}
}

void		print_prompt(t_sh **sh, char *prompt)
{
	if (!prompt || prompt[0] == -1)
	{
		check_if_good_place();
		build_prompt(sh);
		ft_dprintf((*sh)->ttfd, "$> ");
		(*sh)->term->prompt_len = 3;
		(*sh)->prompt[0] = -1;
	}
	else
	{
		ft_strncpy((*sh)->prompt, prompt, 64);
		ft_dprintf((*sh)->ttfd, "\033[0;32m%s\033[0m", prompt);
		(*sh)->term->prompt_len = ft_strlen(prompt) + 3;
	}
	sig_resize(0);
}
