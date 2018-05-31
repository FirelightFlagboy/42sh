/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resig.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:54:11 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 13:39:47 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static inline int	resize_loop(struct winsize *w, t_sh *sh)
{
	int			d;
	sigset_t	sig;
	int			p;

	sigemptyset(&sig);
	sigaddset(&sig, SIGWINCH);
	d = 0;
	while (w->ws_col < 40 || w->ws_row < 20)
	{
		if (d == 0)
		{
			ft_dprintf(sh->ttfd, "\e[2J\e[3J\e[0;0H");
			ft_dprintf(sh->ttfd, "\e[31mterminal too small\e[0m\n");
			sh->term->tc_in = sh->term->tc_len;
			d = 1;
		}
		sigwait(&sig, &p);
		ioctl(0, TIOCGWINSZ, w);
	}
	return (d);
}

static inline void	get_size(t_sh *sh)
{
	struct winsize	w;
	int				d;

	ioctl(0, TIOCGWINSZ, &w);
	d = resize_loop(&w, sh);
	sh->term->ws_col = w.ws_col;
	sh->term->ws_row = w.ws_row;
	sh->term->max_len =\
	((w.ws_col - 0) * (w.ws_row - 1)) - sh->term->prompt_len - 1;
	if (d == 1)
	{
		ft_dprintf(sh->ttfd, "\e[2J\e[3J\e[0;0H");
		print_prompt(&sh, sh->prompt);
		if (sh->buff)
			ft_putstr(sh->buff);
	}
}

void				sig_resize(int s_num)
{
	t_c_tab		*list;
	t_sh		*sh;
	size_t		n;

	n = 0;
	signal(SIGWINCH, sig_resize);
	sh = gtsh(NULL);
	(void)s_num;
	get_size(sh);
	if ((list = get_list(NULL, 0)))
	{
		ft_putstr(sh->buff);
		if (!big_enough(list))
		{
			ioctl(0, TIOCSTI, "n");
			clean_list(list);
			get_list(NULL, 1);
			return ;
		}
		begin_resize_tab(&list, n);
	}
	return ;
}
