/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:23:02 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/02 16:22:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int g_exit;

void	fctsig(int s_num)
{
	t_sh		*sh;
	t_c_tab		*list;

	(void)s_num;
	signal(SIGINT, fctsig);
	sh = gtsh(NULL);
	sh->inhere = 0;
	list = get_list(NULL, 0);
	ft_putstr(tgetstr("cd", NULL));
	if (sh->child)
		return ;
	if (list)
	{
		tab_term(2, sh, 1);
		clean_list(list);
		get_list(NULL, 1);
		ioctl(0, TIOCSTI, "n");
	}
	clean_buffer(&sh);
}

void	handler_child(int sig)
{
	t_sh *sh;

	(void)sig;
	signal(SIGINT, handler_child);
	sh = gtsh(NULL);
}

void	handler_quit(int sig)
{
	t_sh	*sh;
	t_c_tab	*list;

	(void)sig;
	sh = gtsh(NULL);
	list = get_list(NULL, 0);
	if (sh->child)
		kill(sh->child, SIGQUIT);
	ft_hash_free(sh->hash);
	ft_putstr(tgetstr("ve", NULL));
	tcsetattr(STDIN_FILENO, 0, &sh->official);
	closesh(&sh);
	exit(sh->ret);
}
