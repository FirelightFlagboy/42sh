/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 08:55:28 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/05 14:48:40 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					ft_close_fd(int tfd[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (tfd[i] >= 0)
		{
			close(tfd[i]);
			close(i);
		}
		i++;
	}
	return (0);
}

static inline int	ft_redir_input_end(int fd_old, char *file, int tfd[10])
{
	int	new;

	if ((new = open(file, O_RDONLY | O_CLOEXEC)) < 0)
	{
		ft_eprintf("42sh : %s : open error\n", file);
		ft_strdel(&file);
		return (1);
	}
	ft_dup_redir(new, fd_old, tfd);
	ft_strdel(&file);
	return (0);
}

int					ft_redir_input(t_token *token, int index, int tfd[10])
{
	int		old;
	char	*str;
	char	s[64];

	old = (token[index - 1].name == IO_NUMBER) ?\
	token[index - 1].value[0] - '0' : STDIN_FILENO;
	if (token[index].name == DLESS)
	{
		ft_snprintf(s, 64, "/tmp/heredoc-%zo", (intmax_t)token);
		str = ft_strdup(s);
	}
	else
	{
		if (!(str = ft_get_arg(token[index + 1])))
			return (ft_warnx_errn("42sh", (g_errn = ERR_MALLOC)));
		if (ft_access(str, R_OK) && ft_warn2_errn("42sh", str, g_errn))
		{
			ft_strdel(&str);
			return (1);
		}
	}
	return (ft_redir_input_end(old, str, tfd));
}
