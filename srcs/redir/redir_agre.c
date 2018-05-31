/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_agre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 08:56:24 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/26 13:09:47 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static inline int	ft_redir_agre_in_end(\
	t_token *token, int fd_old, int tfd[10])
{
	char	*s;
	int		new;

	if (!(s = ft_get_arg(token[0])))
		return (ft_warnx_errn("42sh", (g_errn = ERR_MALLOC)));
	if (ft_access(s, R_OK))
	{
		ft_warn2_errn("42sh", s, g_errn);
		ft_strdel(&s);
		return (1);
	}
	if ((new = open(s, O_RDONLY | O_CLOEXEC)) < 0)
	{
		ft_eprintf("42sh : %s : error open\n", s);
		free(s);
		return (1);
	}
	ft_dup_redir(new, fd_old, tfd);
	return (0);
}

static inline int	ft_redir_agre_in(t_token *token, int index, int tfd[10])
{
	int		old;
	int		new;

	old = STDIN_FILENO;
	if (token[index - 1].name == IO_NUMBER)
		old = token[index - 1].value[0] - '0';
	if (token[index + 1].value[0] == '-' && token[index + 1].value[1] == 0)
		return (ft_close_redir(old, tfd));
	if (ft_isall_num(token[index + 1].value))
	{
		new = ft_atoi(token[index + 1].value);
		if (new >= 0 && new <= 9\
		&& tfd[new] >= 0)
			return (ft_dup_agre(new, old, tfd));
		return (!!ft_eprintf("42sh : %d : error bad file descriptor\n", new));
	}
	else
		return (ft_redir_agre_in_end(token + index + 1, old, tfd));
	return (0);
}

static inline int	ft_redir_agre_out_end(t_token *token, int old, int tfd[10])
{
	char	*s;
	int		new;

	if (!(s = ft_get_arg(token[0])))
		return (ft_warnx_errn("42sh", (g_errn = ERR_MALLOC)));
	if ((new = open(s, O_TRUNC | OP_FLAGS_W, CREATE_FLAGS)) < 0)
	{
		ft_eprintf("42sh : %s : error open\n", s);
		ft_strdel(&s);
		return (1);
	}
	ft_dup_redir(new, old, tfd);
	ft_strdel(&s);
	return (0);
}

static inline int	ft_redir_agre_out(t_token *token, int index, int tfd[10])
{
	int		old;
	int		new;

	old = STDOUT_FILENO;
	if (token[index - 1].name == IO_NUMBER)
		old = token[index - 1].value[0] - '0';
	if (token[index + 1].value[0] == '-' && token[index + 1].value[1] == 0)
		return (ft_close_redir(old, tfd));
	if (ft_isall_num(token[index + 1].value))
	{
		new = ft_atoi(token[index + 1].value);
		if (new >= 0 && new <= 9\
		&& tfd[new] >= 0)
			return (ft_dup_agre(new, old, tfd));
		return (!!ft_eprintf("42sh : %d : error bad file descriptor\n", new));
	}
	else
		ft_redir_agre_out_end(token + index + 1, old, tfd);
	return (0);
}

int					ft_redir_agre(t_token *token, int index, int tfd[10])
{
	if (token[index].name == LESS_AND)
		return (ft_redir_agre_in(token, index, tfd));
	if (token[index].name == GREAT_AND)
		return (ft_redir_agre_out(token, index, tfd));
	return (0);
}
