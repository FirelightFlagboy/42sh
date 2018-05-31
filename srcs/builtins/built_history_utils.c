/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_history_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 09:39:31 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/30 09:17:37 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_filename(char **av, t_sh *sh)
{
	if (*av == NULL)
		return (sh->hist_dir);
	if (ft_strcmp(*av, "--") == 0)
	{
		if (av[1])
			return (av[1]);
		return (sh->hist_dir);
	}
	return (*av);
}

int		hist_check_good(char *file, int flags)
{
	struct stat st;

	if (file == NULL)
		return (1);
	if (ft_access(file, flags))
	{
		ft_eprintf("history : %s : %s\n", file, ft_strerror(g_errn));
		return (1);
	}
	if (lstat(file, &st))
	{
		ft_eprintf("history : %s : error stat\n", file);
		return (1);
	}
	if (S_ISREG(st.st_mode))
		return (0);
	ft_eprintf("history : %s : not a file\n", file);
	return (1);
}

int		hist_read(t_sh *sh)
{
	char	*filename;
	char	*line;
	char	**ts;
	int		i;
	int		fd;

	if (!(filename = get_filename(sh->cmd + 2, sh))\
	|| hist_check_good(filename, R_OK))
		return (1);
	if ((fd = open(filename, O_RDONLY | O_CLOEXEC)) < 0)
		return (!!ft_eprintf("history : %s : open error\n", filename));
	if (ft_read(fd, &line) == -1\
	&& ft_eprintf("history : %s : error read\n", sh->hist_dir)\
	&& close(fd) != -2)
		return (1);
	if (!(ts = ft_strsplit(line, '\n')))
		malloc_error();
	ft_strdel(&line);
	i = -1;
	while (ts[++i])
		if (ts[i][0])
			hist_add_from_str(ts[i]);
	ft_free_tchar(ts);
	close(fd);
	return (0);
}

int		hist_write(t_sh *sh)
{
	char	*filename;
	t_h_lst	*node;
	int		fd;

	if (!(filename = get_filename(sh->cmd + 2, sh)))
		return (1);
	if ((fd = open(filename, O_TRUNC | OP_FLAGS_W, CREATE_FLAGS)) < 0)
	{
		ft_eprintf("history : %s : open error\n", filename);
		return (1);
	}
	node = sh->history->list;
	while (node && node->next)
		node = node->next;
	while (node)
	{
		if (node->cmd && node->cmd[0])
			ft_dprintf(fd, "%s\n", node->cmd);
		node = node->prev;
	}
	close(fd);
	return (0);
}

int		hist_append(t_sh *sh)
{
	char	*filename;
	t_h_lst	*node;
	int		fd;

	if (!(filename = get_filename(sh->cmd + 2, sh)))
		return (1);
	if ((fd = open(filename, O_APPEND | OP_FLAGS_W, CREATE_FLAGS)) < 0)
	{
		ft_eprintf("history : %s : open error\n", filename);
		return (1);
	}
	node = sh->history->list;
	while (node && node->next)
		node = node->next;
	while (node)
	{
		if (node->cmd)
			ft_dprintf(fd, "%s\n", node->cmd);
		node = node->prev;
	}
	close(fd);
	return (0);
}
