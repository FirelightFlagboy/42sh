/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:37:08 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/07 08:37:00 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_do_redir(int old, int new)
{
	if (old == -1)
		close(new);
	else if (old == -2 || old == new)
		return (0);
	else if (!(dup2(old, new)))
		close(old);
	return (0);
}

int		ft_close_redir(int fd_old, int tfd[10])
{
	if (tfd[fd_old] < 0)
		return (0);
	if (tfd[fd_old] > STDERR_FILENO)
		close(tfd[fd_old]);
	tfd[fd_old] = -1;
	return (0);
}

int		ft_dup_redir(int fd_new, int fd_old, int tfd[10])
{
	if (tfd[fd_old] < 0)
		tfd[fd_old] = fd_new;
	else
	{
		if (tfd[fd_old] > 2)
			close(tfd[fd_old]);
		tfd[fd_old] = fd_new;
	}
	return (0);
}

int		ft_init_tfd(int tfd[10])
{
	int		i;

	i = -1;
	while (++i < 10)
		tfd[i] = -2;
	tfd[0] = STDIN_FILENO;
	tfd[1] = STDOUT_FILENO;
	tfd[2] = STDERR_FILENO;
	return (0);
}

int		ft_redir(t_token *token, int size, int tfd[10])
{
	int	i;

	ft_init_tfd(tfd);
	i = 0;
	while (i < size)
	{
		if (token[i].family == OP_REDIR)
		{
			if (token[i].name == LESS || token[i].name == DLESS)
			{
				if (ft_redir_input(token, i, tfd))
					return (1);
			}
			else if (token[i].name == GREAT || token[i].name == DGREAT)
			{
				if (ft_redir_output(token, i, tfd))
					return (1);
			}
			else if (token[i].name == LESS_AND || token[i].name == GREAT_AND)
				if (ft_redir_agre(token, i, tfd))
					return (1);
		}
		i++;
	}
	return (0);
}
