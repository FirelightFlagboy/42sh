/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:25:27 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/04 09:11:04 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_isall_num(const char *s)
{
	if (*s == 0)
		return (0);
	while (ft_isdigit(*s))
		s++;
	if (*s == 0)
		return (1);
	return (0);
}

int			ft_dup_agre(int fd_new, int fd_old, int tfd[10])
{
	tfd[fd_old] = dup(tfd[fd_new]);
	return (0);
}

char		*get_stop_here(char *stop)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (stop[i])
	{
		if (stop[i] != '"' && stop[i] != '\'')
			stop[p++] = stop[i];
		i++;
	}
	stop[p] = 0;
	return (stop);
}

void		get_heredoc(t_sh *sh, char *stop)
{
	char	p[64];
	char	*s;

	sh->sig = SIG_IGN;
	sh->inhere = 1;
	stop = get_stop_here(stop);
	ft_snprintf(p, 64, (ft_strlen(stop) >= 53)\
	? "heredoc: %.48s...\n$> " : "heredoc: %s > ", stop);
	while (1)
	{
		print_prompt(&sh, p);
		signal(SIGINT, SIG_IGN);
		ft_strdel(&sh->buff);
		read_input(&sh, stop);
		s = sh->buff;
		if ((stop[0] == 0 && (!s || !s[0])) || ft_strcmp(s, stop) == 0)
			break ;
		if (sh->buff)
			ft_dprintf(sh->heredoc_fd, "%s\n", sh->buff);
		else
			ft_putchar_fd('\n', sh->heredoc_fd);
		ft_strdel(&sh->buff);
	}
	ft_strdel(&sh->buff);
}
