/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_history_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 10:50:17 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/11 08:37:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_read(int fd, char **s)
{
	char	*tmp;
	char	*all;
	char	buff[1025];
	int		rt;

	if (s == NULL || fd < 0 || fd > OPEN_MAX)
		return (-1);
	all = NULL;
	while ((rt = read(fd, buff, 1024)) > 0)
	{
		buff[rt] = 0;
		tmp = all;
		if (all)
			ft_asprintf(&all, "%s%s", all, buff);
		else
			all = ft_strdup(buff);
		ft_strdel(&tmp);
	}
	*s = all;
	return (rt);
}

int		load_history_file(t_sh *sh)
{
	int		fd;
	int		i;
	char	*line;
	char	**ts;

	if (hist_check_good(sh->hist_dir, R_OK))
		return (1);
	if ((fd = open(sh->hist_dir, O_RDONLY | O_CLOEXEC)) < 0)
		return (!!ft_eprintf("history : %s : open error\n", sh->hist_dir));
	if (ft_read(fd, &line) == -1\
	&& ft_eprintf("history : %s : error read\n", sh->hist_dir)\
	&& close(fd) != -2)
		return (1);
	if (line == NULL || line[0] == 0)
		return (0);
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

void	save_history_file(t_sh *sh)
{
	int		fd;
	t_h_lst *node;

	if (!sh->hist_dir)
		return ;
	if ((fd = open(sh->hist_dir, O_TRUNC | OP_FLAGS_W, CREATE_FLAGS)) < 0)
	{
		ft_eprintf("history : %s : open error\n", sh->hist_dir);
		return ;
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
}
