/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:48:59 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/24 16:28:45 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					ft_rm_heredoc(uintmax_t addr)
{
	char	s[64];

	ft_snprintf(s, 64, "/tmp/heredoc-%zo", addr);
	unlink(s);
	return (0);
}

static inline int	init_here(uintmax_t addr, char *s)
{
	int		fd;

	ft_snprintf(s, 64, "/tmp/heredoc-%zo", addr);
	if ((fd = open(s, OP_FLAGS_W, CREATE_FLAGS)) < 0)
	{
		ft_eprintf("42sh : %s : error open\n", s);
		return (-1);
	}
	return (fd);
}

int					ft_create_heredoc(char *hd_name, uintmax_t addr)
{
	char	s[64];
	int		fd;
	t_sh	*sh;

	sh = gtsh(NULL);
	fd = init_here(addr, s);
	if (fd < 0)
		return (-1);
	sh->heredoc_fd = fd;
	get_heredoc(sh, hd_name);
	close(fd);
	return (0);
}
